#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
//
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg = 0;

    // itterate through all the pixels supplied
    for(int i = 0; i < height; i++) //y
    {
        for(int j = 0; j < width; j++) //x
        {
            // calculate greyscale average
            avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            // replace pixel tripple with average value
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;

    // itterate through all the pixels
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            // calculate the sepia values
            sepiaRed = (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // replace pixel tripples with sepia calculated value using ternary expression
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : (int) round(sepiaBlue);
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : (int) round(sepiaGreen);
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : (int) round(sepiaRed);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];

    // iterate through every column in the original photo
    for (int col = 0; col < height; col++) //column
    {
        // store each row of TRIPPLES in temp
        for (int row = 0; row < width; row++) //row
        {
            temp[col][row] = image[col][row];
        }

    }

    // re-build the image in reverse using the stored TRIPPLES
    int reverse_index = width;
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            image[col][row] = temp[col][reverse_index];
            reverse_index--;
        }
        reverse_index = 0;
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
