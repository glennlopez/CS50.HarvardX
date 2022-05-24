#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string);
int count_words(string);

int main(void)
{
    string usrInput = get_string("Text: ");
    int letters = count_letters(usrInput);
    int words = count_words(usrInput);




    printf("counter: %d\n", words);

}

// COunts the number of words in a string
int count_words(string s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            counter++;
        }
    }
    counter++; // assumes the last space has a word

    return counter;
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