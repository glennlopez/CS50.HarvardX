#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Prototypes
int ExtractCoins(int penny_qty);

int main(void)
{
    float usrInput;
    int pennyval = 0;

    do
    {
        usrInput = get_float("Change owed: ");
    }
    while (usrInput <= 0);

    //convert input to pennies
    pennyval = round(usrInput * 100);

    printf("%i\n", ExtractCoins(pennyval));


}

// Calculate ammount of coins
int ExtractCoins(int penny_qty)
{
    //coins: 1c, 5c, 10c, 25c
    int penny = 0;
    int nickel = 0;
    int dime = 0;
    int quarter = 0;

    // Extract quarters
    while (penny_qty >= 25)
    {
        quarter++;
        penny_qty -= 25;
    }

    // Extract dimes
    while (penny_qty >= 10)
    {
        dime++;
        penny_qty -= 10;
    }

    // Extract nickles
    while (penny_qty >= 5)
    {
        nickel++;
        penny_qty -= 5;
    }

    // Extract pennies
    while (penny_qty >= 1)
    {
        penny++;
        penny_qty -= 1;
    }

    // debug
    /*
    printf("Quarters: %i\n", quarter);
    printf("Dimes: %i\n", dime);
    printf("Nickels: %i\n", nickel);
    printf("Pennies: %i\n", penny);
    */

    return quarter + dime + nickel + penny;
}