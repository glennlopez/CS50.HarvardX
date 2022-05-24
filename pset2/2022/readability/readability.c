#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);
float calculate_colemanLaiuIndex(int, int, int);

int main(void)
{
    string usrInput = get_string("Text: ");
    int letters = count_letters(usrInput);
    int words = count_words(usrInput);
    int sentences = count_sentences(usrInput);
    int colemanLaiuIndex = calculate_colemanLaiuIndex(letters, words, sentences);

    if (colemanLaiuIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else if (colemanLaiuIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", colemanLaiuIndex);
    }


}

float calculate_colemanLaiuIndex(int l, int w, int s)
{
    float index = 0.0;
    float L = ((float) l / w * 100.0);
    float S = ((float) s / w * 100.0);
    index = round((0.0588 * L) - (0.296 * S) - 15.8);

    return index;
}


int count_sentences(string s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            counter++;
        }
    }

    return counter;
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