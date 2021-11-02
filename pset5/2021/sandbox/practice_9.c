#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int value;
    struct node_struct *next;
    struct  node_struct *prev;
}
node;

void PrintList(node *head);
node *NewNode(int value);

int main()
{
    node *tmp = NULL;
    node *head = NULL;

    tmp = NewNode(11);
    tmp->next = head;
    head = tmp;

    tmp = NewNode(22);
    tmp->next = head;
    head = tmp;

    tmp = NewNode(33);
    tmp->next = head;
    head = tmp;

    PrintList(head);

}

node *HeadInsertNode(node *new_node)
{
    node *updatedList = NULL;

    return updatedList;
}

// Print linked list
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->value);
        tmp = tmp->next;
    }
}

// Create a new linked list node
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));

    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}