#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Todo: prompt for start size - user input must be atleast 9
    int startSize, endSize, n, years;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // Todo: prompt for end size - user end size cannot be lower than start size
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // Todo: Calculate number of years until we reach threashold
    n = startSize;
    years = 0;

    while (n < endSize)
    {
        n = n + (n / 3) - (n / 4);
        years++;
    }

    // Todo: Print number of years
    printf("Years: %i\n", years);
}
