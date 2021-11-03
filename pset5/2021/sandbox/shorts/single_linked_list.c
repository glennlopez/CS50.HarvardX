// https://cs50.harvard.edu/x/2021/shorts/singly_linked_lists/

#include <stdio.h>
#include <stdlib.h>

/* Scope:
 * [x] Create a linked list
 * [x] Search a linked list
 * [x] Insert a new node into a linked list
 * [ ] Delete a single element from the linked list
 * [ ] Delete/Free the linked list nodes
 */

typedef struct sll_node
{
    int value;
    struct sll_node *next;
}
node;

node *NewNode(int value);
void PrintList(node *head);
void Insert(node *new_node, node **head);
node *Find(int value, node *head);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    /* Create a linked list */
    for (int i = 1; i <= 5; i++)
        Insert(NewNode(i), &head);

    /* Search a linked list */
    node *find = Find(2, head);
    if (find != NULL)
        printf("Number %i, was found!\n", find->value);


    PrintList(head);
}

// Search a linked list
node *Find(int value, node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        if (tmp->value == value)
            return tmp;
    return NULL;
}

// Insert a new node in an existing linked list
void Insert(node *new_node, node **head)
{
    new_node->next = *head;
    *head = new_node;
}

// Print contents for the linked list
void PrintList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%i\n", tmp->value);
}

// Malloc a new node in heap memory for a linked list
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->value = value;
    return tmp;
}