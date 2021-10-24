#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int value;
    struct node_struct *prev;
    struct node_struct *next;
}
node;

void PrintList(node *head);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    tmp = malloc(sizeof(int));
    
    tmp->value = 11;
    tmp->prev = NULL;
    tmp->next = NULL;

    // Print Linked List
    PrintList(head);

    // Memory Management
    //TODO:
}

void PrintList(node *head)
{
    node * tmp = head;
    while (head != NULL)
    {
        printf("%i\n", (*tmp).value);
        tmp = tmp->next;
    }
}   