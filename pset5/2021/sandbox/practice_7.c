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
node *FindNode(int node_value, node *head);
void FreeNodes(node *head);
void InsertNodeAtHead(node *node_to_insert, node **head);
node *NewNode(int value);
void InsertNodeAfter(node *target_node, node *node_to_insert);

int main()
{
    node *head = NULL;
    node *tmp = NULL;


    for (int i = 1; i <= 7; i++)
    {
        InsertNodeAtHead(NewNode(i), &head);
    }

    node *find = FindNode(6, head);
    if(find != NULL)
    {
        if (find->prev != NULL)
            printf("Target->prev: %i\n", find->prev->value);
        printf("Target: %i\n", find->value);
        if (find->next != NULL)
            printf("Target->next: %i\n", find->next->value);
    }

    // Test inserting node after 
    InsertNodeAfter(FindNode(5, head), NewNode(999));

    // Print Linked List
    PrintList(head);


    // Memory Management
    FreeNodes(head);
}

node *NewNode(int value)
{
    node *tmp = NULL;
    tmp = malloc(sizeof(node));

    //set node values
    tmp->value = value;
    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}

void InsertNodeAtHead(node *node_to_insert, node **head)
{
    node_to_insert->next = *head;

    //TODO: understand this
    if (*head != NULL)
    {
        (*head)->prev = node_to_insert;
    }
    node_to_insert->prev = NULL;

    *head = node_to_insert;
}

void InsertNodeAfter(node *target_node, node *node_to_insert)
{
    node_to_insert->next = target_node->next;

    // TODO: understand this
    if (node_to_insert->next != NULL)
        node_to_insert->next->prev = target_node;
    node_to_insert->prev = target_node;

    target_node->next = node_to_insert;
}

void FreeNodes(node *head) //TODO: Practice this more
{
    node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;         // set the tmp pointer to head so we can free the node and be able to advance to the next node
        head = head->next;  // set the next pointer for the next loop iteration
        free(tmp);          // free the current node in the loop
    }
}

node *FindNode(int node_value, node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == node_value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void PrintList(node *head)
{
    node * tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->value);
        tmp = tmp->next;
    }
}   