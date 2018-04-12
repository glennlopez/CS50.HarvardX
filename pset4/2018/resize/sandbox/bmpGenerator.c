#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#define IMAGE_WIDTH 3
#define IMAGE_HEIGHT 3

#define BYTE_SIZE 8
#define COLOR_PALETS 3
#define COLOR_DEPTH (BYTE_SIZE * COLOR_PALETS)

#define RGB_R(param) (triple.rgbtBlue = param)

#define FILEHEADER_SIZE 14
#define INFOHEADER_SIZE 40
#define HEADER_SIZE (FILEHEADER_SIZE+INFOHEADER_SIZE)

#define PADDING_SIZE ((4 - (IMAGE_WIDTH * sizeof(RGBTRIPLE)) % 4) % 4)
#define IMAGE_BYTESIZE (((IMAGE_WIDTH * COLOR_PALETS) + PADDING_SIZE) * IMAGE_HEIGHT)
#define FILE_BYTESIZE (HEADER_SIZE+IMAGE_BYTESIZE)

/*
    Draws (n) number of pixel(s) on a file
    BMP ref: http://www.fastgraph.com/help/bmp_header_format.html
*/


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

    /*
        DEFINE FILE HEADER HERE
    */
    //TODO: change bfSize
    bf.bfType = 0x4D42;     // always 0x4D42 for BMP
    bf.bfSize = FILE_BYTESIZE;
    bf.bfReserved1 = 0;     // always 0
    bf.bfReserved2 = 0;     // always 0
    bf.bfOffBits = HEADER_SIZE;
 
    // DEBUG - PRINT OUT HEADER 
    printf("BITMAPFILEHEADER\n");
    printf("bf.bfType: %i\n", bf.bfType);
    printf("bf.bfSize: %i\n", bf.bfSize);
    printf("bf.bfReserved1: %i\n", bf.bfReserved1);
    printf("bf.bfReserved2: %i\n", bf.bfReserved2);
    printf("bf.bfOffBits: %i\n", bf.bfOffBits);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    /*
        DEFINE INFO HEADER HERE
    */
    //TODO: change biWidth, biHeight, biSizeImage
    bi.biSize = INFOHEADER_SIZE;
    bi.biWidth = IMAGE_WIDTH;
    bi.biHeight = IMAGE_HEIGHT;
    bi.biPlanes = 1;        // must be 1
    bi.biBitCount = COLOR_DEPTH;
    bi.biCompression = 0;
    bi.biSizeImage = IMAGE_BYTESIZE;
    bi.biXPelsPerMeter = 2835;  // not important keep at 2835
    bi.biYPelsPerMeter = 2835;  // not important keep at 2835
    bi.biClrUsed = 0;           // not important keep at 0
    bi.biClrImportant = 0;      // not important keep at 0

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

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    /*
        DEFINE PADDING HERE
    */
    //int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int padding = PADDING_SIZE;
    

    // iterate over infile's scanlines
    //for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            /*
                DEFINE RGB VAL HERE
            */
            //triple.rgbtBlue = 0x00;
            RGB_R(0x00);
            triple.rgbtGreen = 0xFF;
            triple.rgbtRed = 0xFF;

            // read RGB triple from infile - copy
            //fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile - paste
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
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



