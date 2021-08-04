#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
             // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V, W, X, Y,  Z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes
int compute_score(string word);

int main(void)
{



    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    // TODO: Print the winner
    // 4. use ternary operation to compare scores and print the result
}

int compute_score(string word)
{
    int score = 0;

    // TODO: Compute and return score for string
    for (int i = 0; word[i] != '\0'; i++)
    {
        // 1. covert char to upper case
        word[i] = toupper(word[i]);

        // 2. remove ascii offset
        word[i] -= 65;

        // 3. reference the POINTS index in the array to figure out the score for each letter and add up the points
        score += POINTS[(int) word[i]];
    }



    //DEBUG
    printf("%i\n", score);

    return 0;
}