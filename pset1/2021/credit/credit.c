#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Prototypes
long GetUserInput(void);
bool isValid(long ccnum);
string CheckCardType(long ccnum);

int main(void)
{
    // get card number from user input
    long cardNumber = GetUserInput();


    // Check card validity and type
    if (isValid(cardNumber))
    {
        string cardType = CheckCardType(cardNumber);
        printf("%s", cardType);
    }
    else
    {
        printf("INVALID\n");
    }

}


// Returns a string (credit card type)
string CheckCardType(long ccnum)
{
    string result = "INVALID\n";
    int cardLen = 1;
    int cardStart = 0;

    /* CALCULATE CARD LEN */
    long ccdigits = 10;
    while (ccdigits < ccnum)
    {
        ccdigits *= 10;
        cardLen++;
    }

    // Calculate 13th, 14th, 15th, and 16th card digit
    long i13 = (ccnum % 10000000000000) / 1000000000000;
    long i14 = (ccnum % 100000000000000) / 10000000000000;
    long i15 = (ccnum % 1000000000000000) / 100000000000000;
    long i16 = (ccnum % 10000000000000000) / 1000000000000000;

    /* CHECK CARD TYPE */
    // Check Visa - 13 or 16 digits, starts with 4
    if (cardLen == 13 && (i13 == 4))
    {
        result = "VISA\n";
    }
    if (cardLen == 16 && (i16 == 4))
    {
        result = "VISA\n";
    }

    // Check American Express - 15 Digits, starts at 34 or 37
    if (cardLen == 15 && (i15 == 3) && ((i14 == 4) || (i14 == 7)))
    {
        result = "AMEX\n";
    }

    // Check MasterCard  - 16 Digits, starts at 51, 52, 53, 54 or 55
    if (cardLen == 16 && (i16 == 5) && ((i15 == 1) || (i15 == 2) || (i15 == 3) || (i15 == 4) || (i15 == 5)))
    {
        result = "MASTERCARD\n";
    }

    return result;
}



// Returns a bool (true) if credit card number is valid
bool isValid(long ccnum)
{
    bool result = false; // default is false

    // PARSE DIGITS
    // store every single digit of the users credit card into its own variable
    long i1 = (ccnum % 10) / 1;
    long i2 = (ccnum % 100) / 10;
    long i3 = (ccnum % 1000) / 100;
    long i4 = (ccnum % 10000) / 1000;
    long i5 = (ccnum % 100000) / 10000;
    long i6 = (ccnum % 1000000) / 100000;
    long i7 = (ccnum % 10000000) / 1000000;
    long i8 = (ccnum % 100000000) / 10000000;
    long i9 = (ccnum % 1000000000) / 100000000;
    long i10 = (ccnum % 10000000000) / 1000000000;
    long i11 = (ccnum % 100000000000) / 10000000000;
    long i12 = (ccnum % 1000000000000) / 100000000000;
    long i13 = (ccnum % 10000000000000) / 1000000000000;
    long i14 = (ccnum % 100000000000000) / 10000000000000;
    long i15 = (ccnum % 1000000000000000) / 100000000000000;
    long i16 = (ccnum % 10000000000000000) / 1000000000000000;

    // invalidate card if not zero (too many digits)
    //long d17 = ccnum % 100000000000000000;
    long i17 = (ccnum % 100000000000000000) / 10000000000000000;
    if (i17)
    {
        return false;
    }

    // CHECKSUM
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
    long checksumA = i2 + i4 + i6 + i8 + i10 + i12 + i14 + i16;
    long checksumB = i1 + i3 + i5 + i7 + i9 + i11 + i13 + i15;

    // 4. if the last digit of the sum is 0, then checksum is passed
    result = ((checksumA + checksumB) % 10 != 0) ? false : true;


    return result;
}



// get users input
long GetUserInput(void)
{
    long input = 0;

    // do not accept 0 or negative numbers
    do
    {
        input = get_long("Number: ");
    }
    while (input <= 0);

    return input;
}