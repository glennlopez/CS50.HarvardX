#include <ctype.h>
#include <stdlib.h>

bool isNumeric(string s)
{
    // check each element in the string for non numeric value
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

string get_cardnumber(string prompt)
{
    string usrInput;
    do
        usrInput = get_string("%s", prompt);
    while (!isNumeric(usrInput));

    return usrInput;
}

int get_cardlength(string s)
{
    // count the elements in the string
    int usrInputCounter;
    for (usrInputCounter = 0; s[usrInputCounter] != '\0'; usrInputCounter++);
    return usrInputCounter;
}

int get_startingdigits(string s)
{
    char starting_numbers[3];
    starting_numbers[0] = s[0];
    starting_numbers[1] = s[1];
    starting_numbers[2] = '\0';

    return atoi(starting_numbers);
}

bool get_checksum(string s) //TODO:
{
    return true;
}

// Print AMEX, MASTERCARD, VISA, or INVALID
void print_results(bool checksum, int startingdigits, int cardlength) //TODO:
{
    /*
        American Express: 15 digits, starts with 34 or 37
        Master Card: 16 digits, starts with 51, 52, 53, 54, or 55
        Visa: 13 or 16 digits, starts with 4
    */

   // AMEX
   if (checksum && (cardlength == 15 && (startingdigits == 34 || startingdigits == 37)))
   {
        printf("AMEX\n");
   }

    // MASTERCARD
    else if (checksum && (cardlength == 16 && (startingdigits >= 51 && startingdigits <= 55)))
    {
        printf("MASTERCARD\n");
    }

   // INVALID
   else
   {
       printf("INVALID\n");
   }



}