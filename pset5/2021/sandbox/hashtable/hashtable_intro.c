#include <stdio.h>
#include <stdlib.h>

#define string char *

int QuickHash(string name, int modval);
int StringLen(string s);

int main()
{
    int const ALPHA = 26;
    string uname[3] = {"One", "Two2", "Three3"};
    int hashTable[ALPHA];

    int a = QuickHash(uname[0], ALPHA);
    printf("%i\n", a);
    int b = QuickHash(uname[1], ALPHA);
    printf("%i\n", b);
    int c = QuickHash(uname[2], ALPHA);
    printf("%i\n", c);

    return 0;
}

/**
 * @brief  Generates an int hash
 * @note   
 * @param  name: string to hash out
 * @param  modval: mod value to limit the max value hashed
 * @retval Returns the int hash value
 */
int QuickHash(string name, int modval)
{
    // get string length
    int nameLen = StringLen(name);
    int hashval = 0;

    for (int i = 0; i < nameLen; i++)
    {
        hashval += name[i];
    }
    
    return hashval % modval;
}

/**
 * @brief  Count the characters in the string
 * @note   
 * @param  s: Accepts a string or char *
 * @retval Returns an int value for the char count
 */
int StringLen(string s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}
