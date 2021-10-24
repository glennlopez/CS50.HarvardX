
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
void InsertNode(node *node_to_insert, node **linked_list);
node *FindNode(int node_value, node *linked_list);

int main()
{

    node *head = NULL;
    node *tmp = NULL;
    
    for (int i = 1; i <= 6; i++)
    {
        InsertNode(NewNode(i), &head);
    }

    // Print list
    PrintList(head);

    // Print Found
    node *find = FindNode(5, head);
    if(find != NULL)
        printf("Found: %i(%p)\n", find->data, head);

    // Memory Management
    FreeList(head);


}

node *FindNode(int node_value, node *linked_list)
{
    node *tmp = linked_list;
    while (tmp != NULL)
    {
        if (tmp->data == node_value)
        {
            return tmp;
        }
        
        tmp = tmp->next;
    }
    return NULL;
}

void InsertNode(node *node_to_insert, node **linked_list)
{
   node_to_insert->next = *linked_list;
   *linked_list = node_to_insert;
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