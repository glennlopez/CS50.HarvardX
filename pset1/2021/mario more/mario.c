#include <stdio.h>
#include <cs50.h>

//prototypes
void GenerateLeftBricks(int unum);
void GenerateRightBricks(int unum);
void GenerateBricks(int unum);

int main(void)
{
    int height;

    // ask user height
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    GenerateBricks(height);
    //GenerateRightBricks(height);
    //GenerateLeftBricks(height);
}

// Generates both left and right bricks
void GenerateBricks(int unum)
{
    // generate left aligned bricks
    for (int y = 0; y < unum; y++)
    {
        // print fillers
        for (int x = (unum - 1); x > y; x--)
        {
            printf(" ");
        }

        // print left hashes
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }

        // print brick spacing
        printf("  ");

        // print right hashes
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }
        printf("\n"); // new line
    }
}

// Generates left bricks only
void GenerateLeftBricks(int unum)
{
    // generate left aligned bricks
    for (int y = 0; y < unum; y++)
    {
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }
        printf("\n"); // new line
    }
}

// Generates right bricks only
void GenerateRightBricks(int unum)
{
    // generate left aligned bricks
    for (int y = 0; y < unum; y++)
    {
        // print fillers
        for (int x = (unum - 1); x > y; x--)
        {
            printf(" ");
        }

        // print hashes
        for (int x = 0; x <= y; x++)
        {
            printf("#");
        }
        printf("\n"); // new line
    }
}