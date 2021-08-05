#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
string caesar(string s, int key);


int main(int argc, string argv[])
{
    string plaintext, ciphertext;

    // return invalid use of argument
    if (argc != 2 || atoi(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1; // error code 1
    }

    // get key
    int key = atoi(argv[1]);

    // get user input
    plaintext = get_string("plaintext: ");

    // encrypt plaintext
    ciphertext = caesar(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);


}

// char shifter
string caesar(string s, int key)
{
    char uppercase_alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowercase_alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; s[i] != '\0'; i++)
    {
        // lowercase alpha shift
        if (isalpha(s[i]) && (islower(s[i])))
        {
            // remove lowercase ascii - 97
            int index = s[i] - 97;

            // add key to index
            index = (index + key) % 26;

            // replace with re-indexed char
            s[i] = lowercase_alpha[index];
        }

        // uppercase alpha shift
        if (isalpha(s[i]) && (isupper(s[i])))
        {
            // remove uppercase ascii - 65
            int index = s[i] - 65;

            // add key to index
            index = (index + key) % 26;

            // replace with re-indexed char
            s[i] = uppercase_alpha[index];
        }
    }
    return s;
}
