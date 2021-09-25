#include "helpers.h"
#include <stdio.h>
#include <math.h>

int isCorner(int y, int x, int height, int width);
int isEdge(int y, int x, int height, int width);

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
        reverse_index = width;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Copy the original image to a temp variable
    int cornerCounter = 0; // debug
    int edgeCounter = 0; //debug

    for (int col = 0; col < height; col++) //y
    {
        // Calculate the box-blur average for every RGBTRIPPLE in the image
        for (int row = 0; row < width; row++) //x
        {
            RGBTRIPLE A, B, C, D, X, E, F, G, H;
            int avgBlue, avgGreen, avgRed;

            // Image Kernel Mapping
            // [A][B][C]
            // [D][X][E]
            // [F][G][H]

            // IF Top Left Corner, exclude:     A,B,C,D,F
            // IF Top Edge, exclude:            A,B,C
            // IF Top Right Corner, exclude:    A,B,C,E,H
            // IF Left Edge, exclude:           A,D,F

        //TODO: (1)
            // IF Right Edge, exclude:          C,E,H
            // IF Bottom Left Corner, exclude:  A,D,F,G,H
            // IF Bottom Edge, exclude:         F,G,H
            // IF Bottom Right Corner. exclude: C,E,H,G,F

            // A
            if( !(isCorner(col, row, height, width) == 1) || !(isEdge(col, row, height, width) == 1) || !(isCorner(col, row, height, width) == 2) || !(isEdge(col, row, height, width) == 4) )
            {
                A.rgbtBlue = image[col - 1][row - 1].rgbtBlue;
            }

            // B
            if( !(isCorner(col, row, height, width) == 1) || !(isEdge(col, row, height, width) == 1) || !(isCorner(col, row, height, width) == 2))
            {
                B.rgbtBlue = image[col - 1][row - 0].rgbtBlue;
            }

            // C
            if( !(isCorner(col, row, height, width) == 1) || !(isEdge(col, row, height, width) == 1) || !(isCorner(col, row, height, width) == 2))
            {
                C.rgbtBlue = image[col - 1][row + 1].rgbtBlue;
            }

            // D
            if( !(isCorner(col, row, height, width) == 1) || !(isEdge(col, row, height, width) == 4) )
            {
                D.rgbtBlue = image[col - 0][row - 1].rgbtBlue;
            }

            X.rgbtBlue = image[col - 0][row - 0].rgbtBlue;

            // E
            if(!(isCorner(col, row, height, width) == 2) )
            {
                E.rgbtBlue = image[col - 0][row + 1].rgbtBlue;
            }

            // F
            if( !(isCorner(col, row, height, width) == 1) || !(isEdge(col, row, height, width) == 4))
            {
                F.rgbtBlue = image[col + 1][row - 1].rgbtBlue;
            }
            G.rgbtBlue = image[col + 1][row - 0].rgbtBlue;

            // H
            if(!(isCorner(col, row, height, width) == 2) )
            {
                H.rgbtBlue = image[col + 1][row + 1].rgbtBlue;
            }






            // Original Green Values
            A.rgbtGreen = image[col - 1][row - 1].rgbtGreen;
            B.rgbtGreen = image[col - 1][row - 0].rgbtGreen;
            C.rgbtGreen = image[col - 1][row + 1].rgbtGreen;
            D.rgbtGreen = image[col - 0][row - 1].rgbtGreen;
            X.rgbtGreen = image[col - 0][row - 0].rgbtGreen;
            E.rgbtGreen = image[col - 0][row + 1].rgbtGreen;
            F.rgbtGreen = image[col + 1][row - 1].rgbtGreen;
            G.rgbtGreen = image[col + 1][row - 0].rgbtGreen;
            H.rgbtGreen = image[col + 1][row + 1].rgbtGreen;



            // Original Red Values
            A.rgbtRed = image[col - 1][row - 1].rgbtRed;
            B.rgbtRed = image[col - 1][row - 0].rgbtRed;
            C.rgbtRed = image[col - 1][row + 1].rgbtRed;
            D.rgbtRed = image[col - 0][row - 1].rgbtRed;
            X.rgbtRed = image[col - 0][row - 0].rgbtRed;
            E.rgbtRed = image[col - 0][row + 1].rgbtRed;
            F.rgbtRed = image[col + 1][row - 1].rgbtRed;
            G.rgbtRed = image[col + 1][row - 0].rgbtRed;
            H.rgbtRed = image[col + 1][row + 1].rgbtRed;

            // RGBTRIPPLE CORNER CASE
            // Top left corner (X,E,G,H)
            if (isCorner(col, row, height, width) == 1)
            {
                /*
                // Calculate average Blue
                avgBlue = round(X.rgbtBlue + E.rgbtBlue +
                G.rgbtBlue + H.rgbtBlue) / 4;

                // Calculate average green
                avgGreen = round(X.rgbtGreen + E.rgbtGreen +
                G.rgbtGreen + H.rgbtGreen) / 4;

                // Calculate average red
                avgRed = round(X.rgbtRed + E.rgbtRed +
                G.rgbtRed + H.rgbtRed) / 4;

                // Place average in temp RGBTRIPPLE container
                temp[col][row].rgbtBlue = avgBlue;
                temp[col][row].rgbtGreen = avgGreen;
                temp[col][row].rgbtRed = avgRed;
                */
            }

            // RGBTRIPPLE EDGE CASE
            else if (isEdge(col, row, height, width) > 0)
            {
                edgeCounter++; // debug - testing EDGE DETECTION
                // TODO:
            }

            // RGBTRIPPLE IS NOT AN EDGE OR CORNER CASE
            else
            {

                // Calculate average blue
                avgBlue = round(A.rgbtBlue + B.rgbtBlue + C.rgbtBlue +
                D.rgbtBlue + X.rgbtBlue + E.rgbtBlue +
                F.rgbtBlue + G.rgbtBlue + H.rgbtBlue) / 9;

                // Calculate average red
                avgRed = round(A.rgbtRed + B.rgbtRed + C.rgbtRed +
                D.rgbtRed + X.rgbtRed + E.rgbtRed +
                F.rgbtRed + G.rgbtRed + H.rgbtRed) / 9;

                // Calculate average green
                avgGreen = round(A.rgbtGreen + B.rgbtGreen + C.rgbtGreen +
                D.rgbtGreen + X.rgbtGreen + E.rgbtGreen +
                F.rgbtGreen + G.rgbtGreen + H.rgbtGreen) / 9;

                // Place average in temp RGBTRIPPLE container
                temp[col][row].rgbtBlue = avgBlue;
                temp[col][row].rgbtGreen = avgGreen;
                temp[col][row].rgbtRed = avgRed;
            }

        }

    }
    printf("\n");
    printf("Corner Count: %i \n", cornerCounter); // debug
    printf("Top Edge Count: %i \n", edgeCounter); // debug

    // re-build the blurred image from the stored TRIPPLES
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            // Replace the original image RGBTRIPPLE with a re-calculated box blured RGBTRIPPLE
            image[col][row] = temp[col][row];
        }

    }






    return;
}



// CORNER DETECTION - FOR BLUR
// Checks to see if RGBTRIPPLE to be AVERAGED is a corner pixel
// 0 = not a corner, 1 = top left, 2 = top right, 3 = bottom left, 4 = bottom right
// x and y = curent pixel location; height and width = photo size
int isCorner(int y, int x, int height, int width)
{
    // check top left corner
    if( (y == 0) && (x == 0) )
    {
        printf("Top left corner pixel found [y:%i, x:%i].\n", y, x); // debug
        return 1; // pixel is at top left corner
    }

    // check top right corner
    if( (y == 0) && (x == width - 1) )
    {
        printf("Top right corner pixel found [y:%i, x:%i].\n", y, x); // debug
        return 2; // pixel is at top left corner
    }

    // check bottom left corner
    if( (y == height - 1) && (x == 0) )
    {
        printf("Bottom left corner pixel found [y:%i, x:%i].\n", y, x); // debug
        return 3; // pixel is at top left corner
    }

    if( (y == height - 1) && (x == width - 1) )
    {
        printf("Bottom right corner pixel found [y:%i, x:%i].\n", y, x); // debug
        return 4; // pixel is at top left corner
    }

    return 0; // not a corner pixel
}


// EDGE DETECTION - FOR BLUR
// Checks to see if RGBTRIPPLE to be AVERAGED is an edge pixel
// 0 = not an edge, 1 = Top edge, 2 = Right edge, 3 = Bottom edge, 4 - Left edge
// x and y = curent pixel location; height and width = photo size
int isEdge(int y, int x, int height, int width)
{
    // check for top edge
    if ( (y == 0) && (x > 0 && x < width - 1) )
    {
        printf("Top edge found [y:%i, x:%i].\n", y, x); // debug
        return 1; // pixel is a top edge
    }

    // check for right edge
    if ( (y > 0 && y < height - 1) && (x == width - 1) )
    {
        printf("Right edge found [y:%i, x:%i].\n", y, x); // debug
        return 2; // pixel is a right edge
    }

    // check for bottom edge
    if ( (y == height - 1) && (x > 0 && x < width - 1) )
    {
        printf("Bottom edge found [y:%i, x:%i].\n", y, x); // debug
        return 3; // pixel is a bottom edge
    }

    // check for left edge
    if ( (y > 0 && y < height - 1) && (x == 0) )
    {
        printf("Left edge found [y:%i, x:%i].\n", y, x); // debug
        return 4; // pixel is a left edge
    }

    return 0; // not an edge pixel
}

