#include <stdio.h>
#include <stdlib.h> // for malloc
#include <stdbool.h>
#include<string.h>


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

int main ()
{
    // Hashtable params
    const int BUCKETSIZE = 26;
    node *hash_table[BUCKETSIZE];

    // File pointer params
    const char *filename = "small";
    FILE *textfile = fopen(filename, "r");


    // Read string into a buffer and copy buffer to linked list
    char buffer[180];
    while (fscanf(textfile, "%s", buffer) != EOF)
    {
        AddNode(&hash_table[0], buffer);
    }


    PrintList(hash_table[0]);
    fclose(textfile);
    return 0;
}










    // TODO - Decide where the word will go in the hashtable using a hash function
    // Hash Function
    // Takes a word as input
    // Outputs a number corresponding to which "bucket" to store the word in


// STEP 1. Loads dictionary into memory, returning true if successful, else false - Load all of the words in the dictionary into datastructure (hashtable)
bool load(const char *dictionary)
{
    // TODO:
    // Open dictionary file
        // loop(for each word in the dictionary){ ...
            // Use: fopen() -> check for NULL
            // Use: fscanf(file, "%s", word) -> fscanf will return EOF at the end of the file
        // .. end fscanf loop at EOF}

    // Read strings from the file one at a time
    // Create a new node for each word
    // Hash word to obtain a hash value
    // Insert node into hash table at that location

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
