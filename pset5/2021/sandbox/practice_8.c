#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int value;
    struct node_struct *next;
    struct node_struct *prev;
}
node;

void PrintList(node *head);
node *CreateNode(int value);
void FreeNodes(node *head);
void InsertNode(node *node_to_insert, node **head);

int main()
{
    node *tmp = NULL;
    node *head = NULL;

    tmp = CreateNode(11);
    tmp->next = head;
    tmp->prev = tmp->prev;
    head = tmp;

    tmp = CreateNode(22);
    tmp->next = head;
    tmp->prev = tmp;
    head = tmp;

    tmp = CreateNode(33);
    tmp->next = head;
    tmp->prev = tmp;
    head = tmp;


    for (node *debug = tmp; debug != NULL; debug = debug->next)
    {
        if (debug->prev != NULL)
            printf("Prev: %i\n", debug->prev->value);
        printf("Target: %i\n", debug->value);     //segfault
        if (debug->next != NULL)
            printf("Next:%i\n", debug->next->value);
        printf("\n");
    }
    

    // print list
    PrintList(head);

    // free nodes
    FreeNodes(head);

    return 0;
}

/**
 * @brief  
 * @note   
 * @param  *node_to_insert: 
 * @param  **head: 
 * @retval None
 */
void InsertNode(node *node_to_insert, node **head)
{
    //TODO:
    
}

// Free Node Memory
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

// Create  New Node
node *CreateNode(int value)
{
    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

// Print Linked List
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->value);
        tmp = tmp->next;
    }
}

// Insert Node at head

// Find Node

// Insert Node after a specific node value