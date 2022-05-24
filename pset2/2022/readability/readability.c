#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string s);

int main(void)
{
    string usrInput = get_string("Text: ");
    int letters = count_letters(usrInput);

    

    printf("counter: %d\n", letters);

}


// Counts the number of letters in a string
int count_letters(string s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isalnum(s[i]))
        {
            counter++;
        }
    }

    return counter;
}