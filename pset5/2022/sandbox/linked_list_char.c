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
const unsigned int N = 26;
node *table[N];

int main ()
{

    // Step 1. demo
    load("large");


    PrintList(table[0]);
    return 0;
}


// STEP 2. Hashes word to a number - Take a word and run a hash function on it, returning some number that coresponds with the word
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}



// STEP 1. Loads dictionary into memory, returning true if successful, else false - Load all of the words in the dictionary into datastructure (hashtable)
bool load(const char *dictionary)
{
    // File pointer params
    const char *filename = dictionary;
    FILE *textfile = fopen(filename, "r");

    // Demo - placing words into diffrent buckets in the hashtable
    char buffer[200];
    while (fscanf(textfile, "%s", buffer) != EOF)
    {
        AddNode(&table[hash(buffer)], buffer);
    }



    fclose(textfile);

    return false;
}





// Create a new node in heap
node *NewNode(char* data)
{
    // allocate memory in heap
    node *newNode = NULL;
    newNode = malloc(sizeof(node));

    // check if enough memory is available
    if (newNode != NULL)
    {
        newNode->word = malloc(strlen(data) + 1);
        strcpy(newNode->word, data);
        newNode->next = NULL;
    }
    else
    {
        free(newNode);
        printf("Heap overflow! - Failed to allocate node in heap.\n");
        return 0;
    }

    return newNode;
}


// Add a node to the list
void AddNode(node **head, char *word)
{
    node *tmp = NewNode(word);
    tmp->next = *head;
    *head = tmp;
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
