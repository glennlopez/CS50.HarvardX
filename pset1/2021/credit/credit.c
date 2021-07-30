#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*
 * VISA, MASTER CARD, DISCOVERY = 16 DIGITS
 * AMEX / AMERICAN EXPRESSS = 15 DIGITS
 */

// Prototypes
long GetUserInput(void);
bool isValid(long ccnum);

int main(void)
{
    // todo: get card number from user input
    long cardNumber = GetUserInput();

    // todo: calculate the checksum
    if(isValid(cardNumber))
    {
        printf("VALID!\n");
    }



    // todo: check for card len and starting digits

    // todo: print "AMEX", "MASTERCARD", "VISA", or "INVALID"

    //debug
    //printf("Credit Card: %ld \n", cardNumber);
}

// calculate the checksum and check if the number is a valid credit card number
bool isValid(long ccnum)
{
    bool result = false;

    //store single digits of the card - do not use arrays!
    long d1 = ccnum % 10;
    int i1 = d1;
    printf("%i\n", i1);

    long d2 = ccnum % 100;
    int i2 = (d2 - d1) / 10;

    long d3 = ccnum % 1000;
    int i3 = (d3 - d2) / 100;

    long d4 = ccnum % 10000;
    int i4 = (d4 - d3) / 1000;

    long d5 = ccnum % 100000;
    int i5 = (d5 - d4) / 10000;
    
    long d6 = ccnum % 1000000;
    int i6 = (d6 - d5) / 100000;

    long d7 = ccnum % 10000000;
    int i7 = (d7 - d6) / 1000000;
    
    long d8 = ccnum % 100000000;
    int i8 = (d8 - d7) / 10000000;

    long d9 = ccnum % 1000000000;
    int i9 = (d9 - d8) / 100000000;

    long d10 = ccnum % 10000000000;
    int i10 = (d10 - d9) / 1000000000;

    long d11 = ccnum % 100000000000;
    int i11 = (d11 - d10) / 10000000000;

    long d12 = ccnum % 1000000000000;
    int i12 = (d12 - d11) / 100000000000;

    long d13 = ccnum % 10000000000000;
    int i13 = (d13 - d12) / 1000000000000;



    return result;
}


// get users input
long GetUserInput(void)
{
    long input = 0;

    // check for non negative values
    do
    {
        input = get_long("Number: ");
    }
    while(input <= 0);

    return input;
}