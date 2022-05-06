// https://cs50.harvard.edu/x/2022/psets/1/mario/more/
#include <cs50.h>
#include <stdio.h>

// function for generating bricks
void generateBricks(int height)
{
    for (int y = 0; y < height; y++)
    {
        //spacer
        for (int x = (height - 1); x > y; x--)
        {
            printf(" ");
        }

        // brick left side
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }

        // the gap
        printf("  ");

        // brick right side
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}


/*  M A I N  */
int main(void)
{
    int usrString;
    do
    {
        usrString = get_int("Height: ");
    }
    while (usrString > 8 || usrString <= 0);
    generateBricks(usrString);
}