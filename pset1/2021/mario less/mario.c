#include <stdio.h>
#include <cs50.h>

//prototypes
void GenerateLeftBricks(int unum);
void GenerateRightBricks(int unum);

int main(void)
{
    int height;

    // ask user height
    do
    {
        height = get_int("Height: ");
    }
    while ((height < 1) || (height > 8));

    //GenerateLeftBricks(height);
    GenerateRightBricks(height);



}

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