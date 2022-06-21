#include <stdio.h>
#include <stdlib.h> // for malloc

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
void AddNodeToHead(node **head, char *word);
void PrintList(node *head);

int main ()
{

    // Hashtable Buckets
    //node *bucket_0 = NULL;  // A
    //node *bucket_1 = NULL;  // B
    //node *bucket_2 = NULL;  // C

    node *hash_table[3];

    // TODO - Decide where the word will go in the hashtable
    if ()
    {

    }

    AddNodeToHead(&hash_table[0], "Apple");
    AddNodeToHead(&hash_table[0], "Ant");
    AddNodeToHead(&hash_table[1], "Bread");
    AddNodeToHead(&hash_table[2], "Cat");
    AddNodeToHead(&hash_table[2], "Coat");

    PrintList(hash_table[2]);





    return 0;
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
        (*newNode).word = data;
        (*newNode).next = NULL;
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
void AddNodeToHead(node **head, char *word)
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
