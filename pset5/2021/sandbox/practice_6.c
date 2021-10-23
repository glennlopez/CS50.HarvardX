
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

void PrintList(node *head);
void FreeList(node *head);
node *NewNode(int node_value);

int main()
{

    node *head = NULL;
    node *tmp = NULL;

    tmp = NewNode(11);
    tmp->next = head;
    head = tmp;

    tmp = NewNode(22);
    tmp->next = head;
    head = tmp;



    // Print list
    PrintList(head);

    // Memory Management
    FreeList(head);


}

void InsertNode(node *node_to_insert, node **linked_list)
{
    //TODO: insert the new node to an existing linked list
    /*
    tmp->next = head;
    head = tmp;
    */
}

node *NewNode(int node_value)
{
    node *tmp = malloc(sizeof(node));
    tmp->data = node_value;
    tmp->next = NULL;
    return tmp;
}

void FreeList(node *head)
{
    node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
    }
}