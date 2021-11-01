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
void InsertNodeAtHead(node *node_to_insert, node **head);

int main()
{
    node *tmp = NULL;
    node *head = NULL;

    // Create a linked list
    for (int i = 1; i <= 10; i++)
    {
        InsertNodeAtHead(CreateNode(i), &head);
    }

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
void InsertNodeAtHead(node *node_to_insert, node **head)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
}

/**
 * @brief  Free the memory allocated in heap used by the nodes in the linked list
 * @note   
 * @param  *head: Pointer the the head of the linked list
 * @retval None
 */
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

/**
 * @brief   Mallocs a node size memory in heap for a new node
 * @note   
 * @param  value: Set the value of the new node
 * @retval 
 */
node *CreateNode(int value)
{
    node *tmp = NULL;
    tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

/**
 * @brief  Print the value of the node in a linked list
 * @note   
 * @param  *head: Pointer to the head of the linked list
 * @retval None
 */
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->value);
        tmp = tmp->next;
    }
}

// Find Node

// Insert Node after a specific node value