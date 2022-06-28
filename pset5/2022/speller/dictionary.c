// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// prototypes
void FreeLinkedList(node *list);

// Number of buckets in hash table
const unsigned int N = 330;
node *table[N];

// STEP 4. Returns true if word is in dictionary, else false - Check if the word is in the dictionary or not (ie: is it correctly spelled or not)
bool check(const char *word)
{
    // Hash word to obtain the hash value
    unsigned int hashval = hash(word);

    // TODO - traverse the linked list bucket until NULL
    node *tmp = table[hashval];
    while (tmp != NULL)
    {
        // Traverse until NULL or the word is found
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }

    return false;   // word not found
}


// STEP 2. Hashes word to a number - Take a word and run a hash function on it, returning some number that coresponds with the word
unsigned int hash(const char *word)
{
    const char alphadex[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int indexSum = 0;

    int i;
    for (int j = 0; word[j] != '\0'; j++)
    {
        i = 0;
        while (isalpha(word[j]) && (alphadex[i] != tolower(word[j])))
        {
            i++;
            if (alphadex[i] == tolower(word[j]))
            {
                indexSum += i;
                continue;
            }
        }
    }

    return indexSum % N;
}




// STEP 1. Loads dictionary into memory, returning true if successful, else false - Load all of the words in the dictionary into datastructure (hashtable)
bool load(const char *dictionary)
{

    // File pointer params
    FILE *textfile = fopen(dictionary, "r");
    if (textfile == NULL)
    {
        // cannot open file or file doesnt exist
        return false;
    }

    // place textfile words in buffer
    char buffer[LENGTH + 1];
    while (fscanf(textfile, "%s", buffer) != EOF)
    {
        // allocate memory in heap
        node *newNode = NULL;
        newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            // not enough memory
            free(newNode);
            return false;
        }

        // add word in buffer to the new node; also NULL the next pointer
        strcpy(newNode->word, buffer);
        newNode->next = NULL;

        // insert new node into head of linked list
        newNode->next = table[hash(buffer)];
        table[hash(buffer)] = newNode;

        // keep track of the list size
        //ListSize++;
    }

    fclose(textfile);
    return true;
}





// STEP 3. Returns number of words in dictionary if loaded, else 0 if not yet loaded - Returns how many words are in your dictionary
unsigned int size(void)
{
    int size = 0;

    for (int i = 0; i < N; i++)
    {
        node *list = table[i];

        while (list != NULL)
        {
            size++;
            list = list->next;
        }
    }

    return size;
}

// STEP 5. Unloads dictionary from memory, returning true if successful, else false - Free Memory
bool unload(void)
{
    unsigned int bucketsize = N;
    while (bucketsize != 0)
    {
        FreeLinkedList(table[bucketsize]);
        bucketsize--;
    }
    return true;
}


// Recursively free memory from linked list
void FreeLinkedList(node *list)
{
    // base case - exit when node is null
    if (list == NULL)
    {
        return;
    }

    // recursive case - go to the next pointer to see if its null
    FreeLinkedList(list->next);

    // do this after returning from the recursive case above
    free(list);
}
