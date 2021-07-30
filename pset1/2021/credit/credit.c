#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*
 * VISA, MASTERCARD, DISCOVERY = 16 DIGITS
 * AMEX / AMERICAN EXPRESSS = 15 DIGITS
 */

// Prototypes
long GetUserInput(void);
bool isValid(long ccnum);
string CheckCardType(long ccnum);

int main(void)
{
    // todo: get card number from user input
    long cardNumber = GetUserInput();

    // todo: calculate the checksum
    if(isValid(cardNumber))
    {
        CheckCardType(cardNumber);
    }
    else
    {
         printf("INVALID!\n"); //debug
    }





    // todo: print "AMEX", "MASTERCARD", "VISA", or "INVALID"

    //debug
    //printf("Credit Card: %ld \n", cardNumber);
}


// Returns a string (credit card type)
string CheckCardType(long ccnum)
{
    string result = "INVALID";

    // Check Card length
    int cardLen = 1;

    // todo: change this to a for loop
    long ccdigits = 10;
    while(ccdigits < ccnum)
    {
        ccdigits *= 10;
        cardLen++;
    }

    // todo: Check Starting Digits

    return result;
}


// Returns a bool (true) if credit card number is valid
bool isValid(long ccnum)
{
    bool result = false; // default is false

    /* PARSE DIGITS */
    // store every single digit of the users credit card into its own variable
    // note: a temp variable is used to make sure no information is lost during cascading math operations
    long d1 = ccnum % 10;
    int i1 = d1;
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
    long d14 = ccnum % 100000000000000;
    int i14 = (d14 - d13) / 10000000000000;
    long d15 = ccnum % 1000000000000000;
    int i15 = (d15 - d14) / 100000000000000;
    long d16 = ccnum % 10000000000000000;
    int i16= (d16 - d15) / 1000000000000000;

    // invalidate card if not zero (too many digits)
    long d17 = ccnum % 100000000000000000;
    int i17= (d17 - d16) / 10000000000000000;
    if(i17)
    {
        return false;
    }

    /* CHECKSUM */
    // 1. multiply every second digit starting from the second most right number by 2
    // 2. if the result from multiplying by 2 is greater than 9, the resulting digits are added
    //    example: 7 * [2] = (14) -> (1 + 4) = 5    vs   3 * [2] = 6
    //    14 has two digits (1, and 4) so they are added, 5 is used
    //    6 has one digit, this is kept as is
    i2 = (i2 * 2 < 10) ? i2 * 2 : (((i2 * 2) % 10) + ((i2 * 2) / 10));
    i4 = (i4 * 2 < 10) ? i4 * 2 : (((i4 * 2) % 10) + ((i4 * 2) / 10));
    i6 = (i6 * 2 < 10) ? i6 * 2 : (((i6 * 2) % 10) + ((i6 * 2) / 10));
    i8 = (i8 * 2 < 10) ? i8 * 2 : (((i8 * 2) % 10) + ((i8 * 2) / 10));
    i10 = (i10 * 2 < 10) ? i10 * 2 : (((i10 * 2) % 10) + ((i10 * 2) / 10));
    i12 = (i12 * 2 < 10) ? i12 * 2 : (((i12 * 2) % 10) + ((i12 * 2) / 10));
    i14 = (i14 * 2 < 10) ? i14 * 2 : (((i14 * 2) % 10) + ((i14 * 2) / 10));
    i16 = (i16 * 2 < 10) ? i16 * 2 : (((i16 * 2) % 10) + ((i16 * 2) / 10));

    // 3. Add up all the numbers
    int checksumA = i2 + i4 + i6 + i8 + i10 + i12 + i14 + i16;
    int checksumB = i1 + i3 + i5 + i7 + i9 + i11 + i13 + i15;

    // 4. if the last digit of the sum is 0, then checksum is passed
    result = ((checksumA + checksumB) % 10 != 0) ? false : true;


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