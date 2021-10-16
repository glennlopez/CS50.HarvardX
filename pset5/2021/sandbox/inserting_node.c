/* Insert a node in an existing Linked List */
#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

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

// TODO: insert a new node at the head of the list
node *InsertAtHead(node *head, node *node_to_insert)
{
    head = node_to_insert;

    return NULL;
}

/**
 * @brief  Displays the data values in the linked list on the console
 * @note   Prints to console
 * @param  *head: pointer to the linked list head
 * @retval None
 */
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

/**
 * @brief  Creates a new linked list node allocated in HEAP memory.
 * @note   
 * @param  number: Intiger value to set inside of data
 * @retval returns the pointer to the newly allocated node
 */
node *NewNode(int number)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = number;
    new_node->next = NULL;

    return new_node;
}