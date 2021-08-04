#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Globals
int letter_count;
int word_count;
int sentence_count;
int index;

// Prototypes
int countletters(string s);
int countwords(string s);
int countsentences(string s);
float cli_calc(int l, int w, int s);

int main(void)
{
    // 1. Prompt user for an input
    string usrInput = get_string("Text: ");

    // 2. Count the number of letters in the string
    letter_count = countletters(usrInput);

    // 3. Count the number of words in the string
    word_count = countwords(usrInput);

    // 4. Count the number of sentences in the string
    sentence_count = countsentences(usrInput);

    // 5. Calculate the Coleman-Liau Index
    index = cli_calc(letter_count, word_count, sentence_count);
    if (index < 1) // minimums
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16) // maximum
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}




// Calculate the Coleman-Liau Index
float cli_calc(int l, int w, int s)
{
    /*
     * L = Letters / Words * 100
     * S = Sentences / Words * 100
     * INDEX = 0.0588 * L - 0.296 * S - 15.8
     */

    index = 0.0;
    float L = ((float) l / w * 100.0);
    float S = ((float) s / w * 100.0);
    index = round((0.0588 * L) - (0.296 * S) - 15.8);

    return index;
}

// Count the number of sentences in a string
int countsentences(string s)
{
    sentence_count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == '.') || (s[i] == '?') || (s[i] == '!'))
        {
            sentence_count++;
        }
    }

    return sentence_count;
}

// Counts the number of words in a string
int countwords(string s)
{
    word_count = 1; // start at 1 becuase last word doesnt have a space after it

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            word_count++;
        }
    }

    return word_count;
}

// Counts the number of letters in a string
int countletters(string s)
{
    letter_count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        // only count alpha
        if (isalpha(s[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}