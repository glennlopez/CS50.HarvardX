#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Todo: prompt for start size - user input must be atleast 9
    int startSize;
    do{
        startSize = get_int("Start Size: ");
    }
    while(startSize < 9);

    // Todo: prompt for end size - user end size cannot be lower than start size

    // Todo: Calculate number of years until we reach threashold

    // Todo: Print number of years
}
