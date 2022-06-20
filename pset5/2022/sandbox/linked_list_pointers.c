#include <stdio.h>
#include <stdlib.h>


// node datatype
typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

node *NewNode(int number);
void PrintList(node *head);

int main ()
{
    // empty null pointers
    node *head = NULL;
    node *tmp = NULL;

    // Link 0
    tmp = NewNode(100);
    head = tmp;

    // Link 1
    tmp = NewNode(111);     // create new temp node in heap
    head->next = tmp;       // point the heads next to tmp pointer

    // Link 2
    tmp = NewNode(222);
    head->next->next = tmp;

    // Link 3
    tmp = NewNode(333);
    head->next->next->next = tmp;

    // Print linked list to console
    PrintList(head);

    return 0;
}


// NEW NODE
node *NewNode(int number)
{
    // allocate memory to heap
    node *new = malloc(sizeof(node));

    // set list data
    new->data = number;

    // set next pointer to null
    new->next = NULL;

    // return newly created pointer
    return new;
}


// PRINT LINK LIST TO CONSOLE
void PrintList(node *head)
{
    /*
    printf("link 0: %i \n", head->data);
    printf("link 1: %i \n", head->next->data);
    printf("link 2: %i \n", head->next->next->data);
    printf("link 3: %i \n", head->next->next->next->data);
    */
    node *loop = NULL;
    do
    {
        loop = head;
        printf("link: %i\n", loop->data);
        head = loop->next;
    }
    while(loop->next != NULL);
}