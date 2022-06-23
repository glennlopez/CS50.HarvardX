#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/* TODO
    [x] Create node
    [X] Add node to Linked List
    [x] Display Linked List
    [x] Free Linked List
*/

// node struct
typedef struct node_struct
{
    char *word;
    struct node_struct *next;
}
node;

// Prototypes
node *NewNode(char *word);
void AddNode(node **head, char *word);
void PrintList(node *head);
bool load(const char *dictionary);
unsigned int hash(const char *word);

// Hashtable params
const unsigned int N = 26; // size of bucket
node *table[N];

int main ()
{

    // Step 1. demo
    load("large");


    PrintList(table[3]); // debug - watch table[0]
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



// STEP 1. Loads dictionary into memory, returning true if successful, else false - Load all of the words in the dictionary into datastructure (hashtable)
bool load(const char *dictionary)
{

    // File pointer params
    const char *filename = dictionary;
    FILE *textfile = fopen(filename, "r");
    if (textfile == NULL)
    {
        // cannot open file or file doesnt exist
        return false;
    }

    // place textfile words in buffer
    char buffer[200];
    while (fscanf(textfile, "%s", buffer) != EOF)
    {
        // allocate memory in heap
        node *newNode = NULL;
        newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            // not enough memory
            return false;
        }

        // add word in buffer to the new node; also NULL the next pointer
        newNode->word = malloc(strlen(buffer) + 1);
        strcpy(newNode->word, buffer);
        newNode->next = NULL;

        // insert new node into head of linked list
        newNode->next = table[hash(buffer)];
        table[hash(buffer)] = newNode;
    }

    fclose(textfile);
    return true;
}


// Print Linked List
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->word);
        tmp = tmp->next;
    }
    free(tmp);
}

