/* EXTRA INCLUDE LIBS  */

#include <ctype.h>
#include <stdlib.h>


/*  CHECK IF A STRING IS ALL NUMERIC  */
bool isNumeric(string s)
{
    // check each element in the string for non numeric value
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}



/*  ASK USER FOR CREDIT CARD NUMBER  */
string get_cardnumber(string prompt)
{
    string usrInput;
    do
    {
        usrInput = get_string("%s", prompt);
    }
    while (!isNumeric(usrInput));
    return usrInput;
}




/* COUNT THE CARD LENGTH OF THE CREDIT CARD  */
int get_cardlength(string s)
{
    // count the elements in the string
    int usrInputCounter;
    for (usrInputCounter = 0; s[usrInputCounter] != '\0'; usrInputCounter++);
    return usrInputCounter;
}


/* CHECK STARTING DIGITS OF CARD (2 MOST SIGNIFICANT) */
int get_startingdigits(string s)
{
    char starting_numbers[3];
    starting_numbers[0] = s[0];
    starting_numbers[1] = s[1];
    starting_numbers[2] = '\0';
    return atoi(starting_numbers);
}


/*  PRINT THE RESULT OF CREDIT CARD VALUDATION CHECK  */
void print_results(bool checksum, int startingdigits, int cardlength)
{
    // Checksum pass
    if (checksum == true)
    {
        // Test for AMEX
        if (cardlength == 15 && (startingdigits == 34 || startingdigits == 37))
        {
            printf("AMEX\n");
        }

        // Test for MASTERCARD
        else if (cardlength == 16 && (startingdigits >= 51 && startingdigits <= 55))
        {
            printf("MASTERCARD\n");
        }

        // Test for VISA
        else if ((cardlength == 16 || cardlength == 13) && (startingdigits >= 40 && startingdigits <= 49))
        {
            printf("VISA\n");
        }

        // Everything else..
        else
        {
            printf("INVALID\n");
        }
    }

    // Checksum fails
    else
    {
        printf("INVALID\n");
    }

}


/*  CHECK IF NUMBER IS EVEN  */
bool isEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}


/*  CHECKSUM IMPLIMENTATION USING LUHNS ALGO  */
bool get_checksum(string cardnumber)
{
    int luhn_total = 0;

    // check if cardlength is even
    int cardlength = get_cardlength(cardnumber);

    // convert card number string to array of int
    int cardnumber_int[cardlength];
    for (int i = 0; i < cardlength; i++)
    {
        cardnumber_int[i] = cardnumber[i] - '0';
    }

    // Luhn algo for even card length
    if (isEven(cardlength))
    {
        // itterate through the card number string
        for (int i = 0; i < cardlength; i++)
        {
            if (isEven(i) && ((cardnumber_int[i]) < 5))
            {
                cardnumber_int[i] *= 2;
            }

            else if (isEven(i) && ((cardnumber_int[i]) >= 5))
            {
                char buffer[3];
                sprintf(buffer, "%d", cardnumber_int[i] * 2);
                cardnumber_int[i] = (buffer[0] - '0') + (buffer[1] - '0');
            }
        }
    }

    // Luhn algo for odd card length
    if (!isEven(cardlength))
    {
        // itterate through the card number string
        for (int i = 0; i < cardlength; i++)
        {
            if (!isEven(i) && ((cardnumber_int[i]) < 5))
            {
                cardnumber_int[i] *= 2;
            }

            else if (!isEven(i) && ((cardnumber_int[i]) >= 5))
            {
                char buffer[3];
                sprintf(buffer, "%d", cardnumber_int[i] * 2);
                cardnumber_int[i] = (buffer[0] - '0') + (buffer[1] - '0');
            }
        }
    }

    // sum the card numbers
    for (int i = 0; i < cardlength; i++)
    {
        luhn_total += cardnumber_int[i];
    }

    // valudate if card number mods to zero
    if (luhn_total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
