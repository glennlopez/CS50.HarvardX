#include <cs50.h>
#include <stdio.h>

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



void print_results(bool checksum, int startingdigits, int cardlength)
{
   if (checksum && (cardlength == 15 && (startingdigits == 34 || startingdigits == 37)))
        printf("AMEX\n");
    else if (checksum && (cardlength == 16 && (startingdigits >= 51 && startingdigits <= 55)))
        printf("MASTERCARD\n");
    else if ((cardlength == 16) && (startingdigits >= 40 && startingdigits <= 49))
        printf("VISA\n");
   else
       printf("INVALID\n");
}



bool isEven(int num)
{
    if(num % 2 == 0)
        return true;
    return false;
}



bool get_checksum(string cardnumber)
{
    int luhn_total = 0;

    // check if cardlength is even
    int cardlength = get_cardlength(cardnumber);

    // convert card number string to array of int
    int cardnumber_int[cardlength];
    for (int i = 0; i < cardlength; i++)
        cardnumber_int[i] = cardnumber[i] - '0';

    // Luhn algo for even card length
    if (isEven(cardlength))
    {
        // itterate through the card number string
        for (int i = 0; i < cardlength; i++)
        {
            if (isEven(i) && ((cardnumber_int[i]) < 5))
                cardnumber_int[i] *= 2;

            else if (isEven(i) && ((cardnumber_int[i]) >= 5))
            {
                char buffer[3];
                sprintf(buffer, "%d", cardnumber_int[i]*2);
                cardnumber_int[i] = (buffer[0] - '0') + (buffer[1] - '0');
            }
        }
    }

    // Luhn algo for even card length
    if (!isEven(cardlength))
    {
        // itterate through the card number string
        for (int i = 0; i < cardlength; i++)
        {
            if (!isEven(i) && ((cardnumber_int[i]) < 5))
                cardnumber_int[i] *= 2;

            else if (!isEven(i) && ((cardnumber_int[i]) >= 5))
            {
                char buffer[3];
                sprintf(buffer, "%d", cardnumber_int[i]*2);
                cardnumber_int[i] = (buffer[0] - '0') + (buffer[1] - '0');
            }
        }
    }

    for (int i = 0; i < cardlength; i++)
        luhn_total += cardnumber_int[i];

    if (luhn_total % 10 == 0)
        return true;
    else
        return false;
}








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




