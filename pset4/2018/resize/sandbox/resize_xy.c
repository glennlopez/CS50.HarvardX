#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#define SCALE_FACTOR 2 // change this

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // keep track of old data
    int old_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int old_biWidth = bi.biWidth;
    int old_biHeight = abs(bi.biHeight);

    // add scaled changes to original
    bi.biWidth *= SCALE_FACTOR;
    bi.biHeight *= SCALE_FACTOR;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = (((bi.biWidth * sizeof(RGBTRIPLE)) + padding) * abs(bi.biHeight));
    bf.bfSize = (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // NEW HEADERS
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // BUFFER
    RGBTRIPLE triple[old_biHeight][old_biWidth];

    // READ PIXELS TO BUFFER
    for (int i = 0; i < old_biHeight; i++)
    {
        for (int j = 0; j < old_biWidth; j++)
        {
            // read each pixel to input file pointer
            fread(&triple[i][j], sizeof(RGBTRIPLE), 1, inptr);
        }
        // skip reading old data padding
        fseek(inptr, old_padding, SEEK_CUR);
    }

    // WRITE PIXELS FROM BUFFER
    int index_x = 0;    int index_y = 0;
    for (int i = 0; i < old_biHeight; i++)
    {
        for (int scale_y = 0; scale_y < SCALE_FACTOR; scale_y++)
        {
            // write new scanline to output
            for (int j = 0; j < old_biWidth; j++)
            {
                // write each pixel by scale factor
                for (int scale_x = 0; scale_x < SCALE_FACTOR; scale_x++)
                {
                    fwrite(&triple[index_y][index_x], sizeof(RGBTRIPLE), 1, outptr); //fixme
                }
                // increment to next pixel
                index_x++;
            }
            // reset index_x to 0 after scanline completion
            index_x = 0;

            if (scale_y >= SCALE_FACTOR - 1)
            {
                // increment to the next scanline
                index_y++;
            }

            // add padding after scanline
            for (int k = 0; k < padding; k++) // padding = new padding
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}