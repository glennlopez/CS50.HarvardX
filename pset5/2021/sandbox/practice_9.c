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
node *InsertNode_Head(node *head, node *new_node);
void InsertNode(node **head, node *new_node);
void FreeNodes(node *head);
node *FindNode(int value, node *head);

//TODO: link the prev nodes properly in all the node funcs

int main()
{
    node *tmp = NULL;
    node *head = NULL;

    /* Generate nodes using a loop */
    for (int i = 1; i <= 10; i++)
        InsertNode(&head, NewNode(i));

    PrintList(head);

    node *find = FindNode(5, head);
    if (find != NULL)
        printf("Found: %i\n", find->value);
    if (find->next != NULL)
        printf("Next: %i\n", find->next->value);
    if (find->prev != NULL)
        printf("Prev: %i\n", find->prev->value);

    /* Memory Management */
    FreeNodes(head);


}

// Find Node
node *FindNode(int value, node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}

// Free Nodes
void FreeNodes(node *head)
{
    node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Insert a new node by passing the address of the head pointer
void InsertNode(node **head, node *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

// Insert a new node by updating the head
node *InsertNode_Head(node *head, node *new_node)
{
    node *new_head = head;

    new_node->next = new_head;
    new_head = new_node;

    return new_head;
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