#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

node *CreateNode(int number);
void PrintList(node *head);

int main()
{

    node *head = NULL;
    node *n = NULL;

    n = CreateNode(12);
    head = n;

    n = CreateNode(22);
    head->next = n;

    n = CreateNode(33);
    head->next->next = n;

    PrintList(head);


}

// print linkedlist
void PrintList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->next;
    }
}


// create and set a new node
node *CreateNode(int number)
{
    node *n = malloc(sizeof(node));
    n->data = number;
    n->next = NULL;

    return n;
}