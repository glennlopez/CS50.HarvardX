#include <stdio.h>
#include <stdlib.h> // for malloc

/* TODO
    [ ] Create node
    [ ] Add node to Linked List
    [ ] Display Linked List
    [ ] Free Linked List
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


int main ()
{
    // set null pointers for tmp and head nodes
    node *head = NULL;
    node *tmp = NULL;

    tmp = NewNode(111);
    tmp->next = head;
    head = tmp;

    tmp = NewNode(222);
    tmp->next = head;
    head = tmp;

    tmp = NewNode(333);
    tmp->next = head;
    head = tmp;

    PrintList(head);





    return 0;
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