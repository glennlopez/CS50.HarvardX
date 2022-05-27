//https://cs50.harvard.edu/x/2022/psets/2/caesar/
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Tasks:
 *  - Get key
 *  - Get plaintext
 *  - Encipher
 *  - Print ciphertext
*/

bool string_isdigit(string);
void encypher(int, string);



int main(int argc, string argv[])
{

    // 1. Get Key
    int key;
    if (argc == 2 && string_isdigit(argv[1]))
    {
        key = atoi(argv[1]);
    }
    else
    {
        // exit program
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Get Plaintext
    string plaintext = get_string("plaintext: ");

    // 3. Encipher
    encypher(key, plaintext);

    // 4. Print ciphertext
    printf("ciphertext: %s\n", plaintext);



}

// Shift the characters as per key
void encypher(int key, string plaintext)
{
    int ascii_lower = 97;
    int ascii_upper = 65;

    // itterate through the plaintext string
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = ((((int)plaintext[i] - ascii_lower) + key) % 26) + ascii_lower;
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = ((((int)plaintext[i] - ascii_upper) + key) % 26) + ascii_upper;
        }
    }
}


// Check is string is all digits
bool string_isdigit(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}


