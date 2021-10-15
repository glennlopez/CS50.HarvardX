/* Insert a node in an existing Linked List */

#include<stdio.h>
#include<stdlib.h>

// node typedef
typedef struct node_struct
{
    int data;
    struct node_struct *next;

}
node;

//protype
node *NewNode(int number);
void PrintList(node *head);


int main()
{
    node *head = NULL;
    node *tmp = NULL;

    // create 4 nodes using a loop
    for (int i = 1; i <=4; i++)
    {
        tmp = NewNode(i);
        tmp->next = head;
        head = tmp;
    }

    // print linked list before insert
    PrintList(head);
    printf("\n");

    // TODO: insert a new node

    // print linked list after insert
    PrintList(head);


}

// print node
void PrintList(node *head)
{
    node *tmp = NULL;
    tmp = head;

    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
    }

}

// create new node
node *NewNode(int number)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = number;
    new_node->next = NULL;

    return new_node;
}