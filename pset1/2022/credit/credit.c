#include <cs50.h>
#include <stdio.h>
#include "credit_helper.h"

int main(void)
{
    // 1. Get number from user
    string cardnumber = get_cardnumber("Number: ");

    // 2. Calculate the checksum
    bool checksum = get_checksum(cardnumber);

    // 3. Get card length and starting digits
    int startingdigits = get_startingdigits(cardnumber);
    int cardlength = get_cardlength(cardnumber);

    // 4. Print AMEX, MASTERCARD, VISA, or INVALID
    print_results(checksum, startingdigits, cardlength);
}




