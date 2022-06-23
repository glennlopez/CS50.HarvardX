#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned int hash(const char *word);

int main ()
{
    printf("hash: %i\n", hash("dog"));
    return 0;
}

// STEP 2. Hashes word to a number - Take a word and run a hash function on it, returning some number that coresponds with the word
unsigned int hash(const char *word)
{                         //1   2   3   4   5   6   7   8   9   10  1   2   3   4   5   6   7   8   9   20  1   2   3   4   5   6
    const char alphadex[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    int indexSum = 0;

    int i = 0;
    while (alphadex[i] != word[0])
    {
        i++;
    }

    return i;
}