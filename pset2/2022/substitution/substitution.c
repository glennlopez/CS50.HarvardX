#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// https://cs50.harvard.edu/x/2022/psets/2/substitution/
/* TODO
 *  1 - Get key
 *  2 - Validate key
 *  3 - Get plaintext
 *  4 - Encipher
 *  5 - Print ciphertext
 */

bool is26CharsLong(string);
bool isAlphaString(string);
bool isNotRepeating(string);
void encipher(string, string);

int main(int argc, string argv[])
{

    // 1. Get key
    string key = argv[1];

    // 2. Validate key
    if (argc != 2)   // incorrect comand line argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!is26CharsLong(argv[1]))  // key does not contain 26 chars
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (!isAlphaString(argv[1])) // key does not contain alphabet only
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    else if (!isNotRepeating(argv[1])) // key contains repeating characters
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // 3. Get plaintext
    string plaintext = get_string("plaintext: ");

    // 4. Encipher
    encipher(plaintext, key);

    // 5. Print ciphertext
    printf("ciphertext: %s\n", plaintext);
}


// Returns true if string is 26 characters long
bool is26CharsLong(string s)
{
    int keyCounter;
    for (keyCounter = 0; s[keyCounter] != '\0'; keyCounter++);

    // key must be 26 characters long
    if (keyCounter != 26)
    {
        return false;
    }

    return true;
}


// Returns true if string is all alpha
bool isAlphaString(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
    }

    return true;
}


// Returns true if string does not have repeating strings
bool isNotRepeating(string s)
{
    for (int target = 0; s[target] != '\0'; target++)
    {
        int repeated = 0;
        for (int compare = 0; s[compare] != '\0'; compare++)
        {
            if (s[compare] == s[target])
            {
                repeated++;
            }
        }
        if (repeated > 1)
        {
            return false;
        }
    }
    return true;
}


// Substitute key into plaintext
void encipher(string plaintext, string key)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        int char_pos;
        char_pos = toupper(plaintext[i]) - 'A';

        // handle upple-case characters
        if (isupper(plaintext[i]))
        {
            plaintext[i] = key[char_pos];
            plaintext[i] = toupper(plaintext[i]);
        }

        // handle lower-case characters
        if (islower(plaintext[i]))
        {
            plaintext[i] = key[char_pos];
            plaintext[i] = tolower(plaintext[i]);
        }
    }
}
