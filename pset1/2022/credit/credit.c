#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// https://cs50.harvard.edu/x/2022/psets/1/credit/
/*
    American Express: 15 digits, starts with 34 or 37
    Master Card: 16 digits, starts with 51, 52, 53, 54, or 55
    Visa: 13 or 16 digits, starts with 4
*/

// prototypes
bool isNumeric(string);
string get_cardnumber(string);
int get_cardlength(string);
int get_startingdigits(string);
bool get_checksum(string);

int main(void)
{
    // 1. Get number from user
    string cardnumber = get_cardnumber("Number: ");

    // 2. Calculate the checksum
    bool checksum = get_checksum(cardnumber); //TODO:

    // 3. Check for card length and starting digits
    int startingdigits = get_startingdigits(cardnumber);
    int cardlength = get_cardlength(cardnumber);

    // 4. Print AMEX, MASTERCARD, VISA, or INVALID
    print_results(checksum, startingdigits, cardlength); //TODO:

    // debug
    printf("%i\n", cardlength);


}




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
    // get user input as a string
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