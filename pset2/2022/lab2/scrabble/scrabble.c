#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else
    {
        char winner = (score1 > score2) ? '1' : '2';
        printf("Player %c wins!\n", winner);
    }



}

int compute_score(string word)
{
    int ascii_offset = 97; // lowercase 'a' is 97th in ascii index
    int score = 0;

    // itterate through the words
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            score += POINTS[tolower(word[i]) - ascii_offset];
        }
    }

    return score;
}
