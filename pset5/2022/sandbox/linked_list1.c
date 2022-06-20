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
    int data;
    struct node_struct *next;
}
node;

// Prototypes
node *NewNode(int data);
void PrintList(node *head);
void AddNodeToHead(node **head, int data);
void FreeLinkedList(node *head);


int main ()
{
    // set null pointers for tmp and head nodes
    node *head = NULL;

    AddNodeToHead(&head, 111);
    AddNodeToHead(&head, 222);
    AddNodeToHead(&head, 333);
    AddNodeToHead(&head, 5432);

    PrintList(head);
    FreeLinkedList(head);





    return 0;
}

// Recursively free memory from linked list
void FreeLinkedList(node *list)
{
    // base case - exit when node is null
    if(list == NULL)
    {
        return;
    }

    // recursive case - go to the next pointer to see if its null
    FreeLinkedList(list->next);

    // free the pointer after checking to see if the next pointer is null
    free(list);
}


// Add a node to the list
void AddNodeToHead(node **head, int data)
{
    node *tmp = NewNode(data);
    tmp->next = *head;
    *head = tmp;
}


// Print Linked List
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
    }
    free(tmp);

}


// Create a new node in heap
node *NewNode(int data)
{
    // allocate memory in heap
    node *newNode = NULL;
    newNode = malloc(sizeof(node));

    // check if enough memory is available
    if (newNode != NULL)
    {
        (*newNode).data = data;
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