#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#define image_width 3       // change this
#define image_height 2      // change this

#define BYTE_SIZE 8
#define COLOR_PALETS 3
#define COLOR_DEPTH (BYTE_SIZE * COLOR_PALETS)

#define FILEHEADER_SIZE 14
#define INFOHEADER_SIZE 40
#define HEADER_SIZE (FILEHEADER_SIZE+INFOHEADER_SIZE)

#define PADDING_SIZE ((4 - (image_width * sizeof(RGBTRIPLE)) % 4) % 4)
#define IMAGE_BYTESIZE (((image_width * COLOR_PALETS) + PADDING_SIZE) * image_height)
#define FILE_BYTESIZE (HEADER_SIZE+IMAGE_BYTESIZE)

// MACROs
#define RGB_R(param) (triple.rgbtRed = param)
#define RGB_G(param) (triple.rgbtGreen = param)
#define RGB_B(param) (triple.rgbtBlue = param)

/*
    Draws (n) number of pixel(s) on a file
    BMP ref: http://www.fastgraph.com/help/bmp_header_format.html
*/

int main()
{
    // filenames
    char *outfile = "rgb2.bmp";

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }



    // SET FILE HEADER
    BITMAPFILEHEADER bf;
    bf.bfType = 0x4D42;     // always 0x4D42 for BMP
    bf.bfSize = FILE_BYTESIZE;
    bf.bfReserved1 = 0;     // always 0
    bf.bfReserved2 = 0;     // always 0
    bf.bfOffBits = HEADER_SIZE;

    // SET INFO HEADER HERE
    BITMAPINFOHEADER bi;
    bi.biSize = INFOHEADER_SIZE;
    bi.biWidth = image_width;
    bi.biHeight = image_height;
    bi.biPlanes = 1;        // must be 1
    bi.biBitCount = COLOR_DEPTH;
    bi.biCompression = 0;
    bi.biSizeImage = IMAGE_BYTESIZE;
    bi.biXPelsPerMeter = 2835;  // not important keep at 2835
    bi.biYPelsPerMeter = 2835;  // not important keep at 2835
    bi.biClrUsed = 0;           // not important keep at 0
    bi.biClrImportant = 0;      // not important keep at 0
    int padding = PADDING_SIZE;


    // DEBUG - PRINT OUT HEADER
    printf("BITMAPFILEHEADER\n");
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

    // DEBUG - MISC
    printf("\nMISC.\n");
    printf("padding: %i\n", padding);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write header from buffer to output file pointer
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // temporary storage
    RGBTRIPLE triple;

    RGB_R(0xFF); RGB_G(0x00); RGB_B(0x00);  // RED
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0x00); RGB_G(0xFF); RGB_B(0x00);  // GREEN
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0x00); RGB_G(0x00); RGB_B(0xFF);  // BLUE
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    // insert required padding
    for (int k = 0; k < padding; k++)
    {
        fputc(0x00, outptr);
    }



    RGB_R(0xFF); RGB_G(0xFF); RGB_B(0x00);  // YELLOW
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0x00); RGB_G(0xFF); RGB_B(0xFF);  // GREENBLUE
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0xFF); RGB_G(0x00); RGB_B(0xFF);  // PINK
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    // insert required padding
    for (int k = 0; k < padding; k++)
    {
        fputc(0x00, outptr);
    }

    /*

    RGB_R(0x00); RGB_G(0x00); RGB_B(0xFF);  // BLUE
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0x00); RGB_G(0x00); RGB_B(0xFF);  // BLUE
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    RGB_R(0x00); RGB_G(0x00); RGB_B(0xFF);  // BLUE
    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

    // insert required padding
    for (int k = 0; k < padding; k++)
    {
        fputc(0x00, outptr);
    }

    */

    // close outfile
    fclose(outptr);

    // success
    return 0;
}



