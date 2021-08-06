#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int ALPHABET_COUNT = 26;

// Prototypes
string substitution(string s, string key);
bool isalpha_string(string s);
bool hasduplicate(string key);


int main(int argc, string argv[])
{
    string plaintext, ciphertext;

    // invalid argument
    if ((argc != 2) || (hasduplicate(argv[1])))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // invalid key length or type
    if ((strlen(argv[1]) != ALPHABET_COUNT) || (!(isalpha_string(argv[1]))))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // get key
    string key = argv[1];

    // get user input
    plaintext = get_string("plaintext: ");

    // encrypt plaintext
    ciphertext = substitution(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}


// check if key has duplicate chars
bool hasduplicate(string key)
{
    int duplicate_counter = 0;

    //change each char to lowercase
    for (int i = 0; key[i] != '\0'; i++)
    {
        key[i] = tolower(key[i]);
    }

    // compare each char with each other
    for (int i = 0; key[i] != '\0'; i++)
    {
        for (int j = 0; key[j] != '\0'; j++)
        {
            if (key[i] == key[j])
            {
                duplicate_counter++;
            }
        }
        if (duplicate_counter > 1)
        {
            return true;
        }
        duplicate_counter = 0;

    }
    return false;
}

// check if char in strings are all alpha
bool isalpha_string(string s)
{
    int result = true;

    // check every alpha-char in the string
    for (int i = 0; s[i] != '\0'; i++)
    {
        // return false if is not alpha
        if (!(isalpha(s[i])))
        {
            result = false;
        }
    }

    return result;
}

// char substitution
string substitution(string s, string key)
{
    char uppercase_alpha[26];
    char lowercase_alpha[26];

    for (int i = 0; key[i] != '\0'; i++)
    {
        uppercase_alpha[i] = toupper(key[i]);
        lowercase_alpha[i] = tolower(key[i]);
    }

    // substitute plaintext with cypher key
    for (int i = 0; s[i] != '\0'; i++)
    {
        // lowercase alpha shift
        if (isalpha(s[i]) && (islower(s[i])))
        {
            // remove lowercase ascii - 97
            int index = s[i] - 97;

            // replace with re-indexed char
            s[i] = lowercase_alpha[index];
        }

        // uppercase alpha shift
        if (isalpha(s[i]) && (isupper(s[i])))
        {
            // remove uppercase ascii - 65
            int index = s[i] - 65;

            // replace with re-indexed char
            s[i] = uppercase_alpha[index];
        }
    }
    return s;
}
