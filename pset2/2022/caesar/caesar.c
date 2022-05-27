//https://cs50.harvard.edu/x/2022/psets/2/caesar/
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Tasks:
 *  - Get key
 *  - Get plaintext
 *  - Encipher
 *  - Print ciphertext
*/

int get_key(int, char **);
bool string_isdigit(string);



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
        return 0;
    }

    // 2. Get Plaintext



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


