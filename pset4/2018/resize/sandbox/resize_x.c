#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#define SCALE_FACTOR 1 // change this


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
    int old_biSizeImage = bi.biSizeImage;
    int old_bfSize = bf.bfSize;

    // add scaled changes to original
    bi.biWidth *= SCALE_FACTOR;
    bi.biHeight *= SCALE_FACTOR;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = (((bi.biWidth * sizeof(RGBTRIPLE)) + padding) * abs(bi.biHeight));
    bf.bfSize = (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage);

    printf("\n\nbi.biWidth * triple: %lu\n", (bi.biWidth * sizeof(RGBTRIPLE)));
    printf("padding: %i\n\n", padding);

    // DEBUG - OLD DATA
    printf("\nOLD DATA\n");
    printf("old_padding: %i\n", old_padding);
    printf("old_biWidth: %i\n", old_biWidth);
    printf("old_biHeight: %i\n", old_biHeight);
    printf("old_biSizeImage: %i\n", old_biSizeImage);
    printf("old_bfSize: %i\n", old_bfSize);

    // DEBUG - NEW DATA
    printf("\nNEW DATA\n");
    printf("new_padding: %i\n", padding);
    printf("new_biWidth: %i\n", bi.biWidth);
    printf("new_biHeight: %i\n", abs(bi.biHeight));
    printf("new_biSizeImage: %i\n", bi.biSizeImage);
    printf("new_bfSize: %i\n", bf.bfSize);

    /*
    // DEBUG - PRINT OUT HEADER
    printf("\nBITMAPFILEHEADER\n");
    printf("bf.bfType: %i\n", bf.bfType);
    printf("bf.bfSize: %i\n", bf.bfSize);
    printf("bf.bfReserved1: %i\n", bf.bfReserved1);
    printf("bf.bfReserved2: %i\n", bf.bfReserved2);
    printf("bf.bfOffBits: %i\n", bf.bfOffBits);
    // DEBUG - PRINT OUT INFO HEADER
    printf("\nBITMAPINFOHEADER\n");
    printf("bi.biSize: %i\n", bi.biSize);
    printf("bi.biWidth: %i\n", bi.biWidth);
    printf("bi.biHeight: %i\n", bi.biHeight);
    printf("bi.biPlanes: %i\n", bi.biPlanes);
    printf("bi.biBitCount: %i\n", bi.biBitCount);
    printf("bi.biCompression: %i\n", bi.biCompression);
    printf("bi.biSizeImage: %i\n", bi.biSizeImage);
    printf("bi.biXPelsPerMeter: %i\n", bi.biXPelsPerMeter);
    printf("bi.biYPelsPerMeter: %i\n", bi.biYPelsPerMeter);
    printf("bi.biClrUsed: %i\n", bi.biClrUsed);
    printf("bi.biClrImportant: %i\n", bi.biClrImportant);
    */


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }



  // DEBUG - HEADER MODIFIERS
    //bi.biWidth = 3;
    //bi.biHeight = 1;
    //padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //bi.biSizeImage = (((bi.biWidth * sizeof(RGBTRIPLE)) + padding) * abs(bi.biHeight));
    //bf.bfSize = (sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + bi.biSizeImage);
  // END OF HEADER MODIFIER DEBUG




    // write NEW HEADERS
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // buffer
    // temp read storage
    // TODO: store pixels in 2D array
    RGBTRIPLE triple[old_biHeight][old_biWidth];    //todo: use parametric var


    // READ PIXELS TO BUFFER
    for (int i = 0; i < old_biHeight; i++)
    {
        for (int j = 0; j < old_biWidth; j++)
        {
            // read each pixel to input file pointer
            fread(&triple[i][j], sizeof(RGBTRIPLE), 1, inptr);
        }
        fseek(inptr, old_padding, SEEK_CUR);
    }

    // WRITE PIXELS FROM BUFFER
    // TODO: scale by SCALE_FACTOR
    for (int i = 0; i < old_biHeight; i++)
    {
        for (int j = 0; j < old_biWidth; j++)
        {
            // write each pixel to output file pointer
            fwrite(&triple[i][j], sizeof(RGBTRIPLE), 1, outptr);
        }

        // add padding
        for (int k = 0; k < padding; k++) // padding = new padding
        {
            fputc(0x00, outptr);
        }
    }












    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}