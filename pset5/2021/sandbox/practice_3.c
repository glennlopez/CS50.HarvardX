#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int number;
    struct node_struct *next;
}
node;

/* Practice List
 * [ ] Print a linked list
 * [x] Create a new node
 * [ ] Find a new node
 * [ ] Insert a node after a value
 * [ ] Insert a node at a specific pointer
 * [ ] Delete a node
 */

void PrintLinkedList(node *head);
node *CreateNode(int value);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    for (int i = 1; i <= 5; i++)
    {
        tmp = CreateNode(i);
        tmp->next = head;
        head = tmp;
    }

    PrintLinkedList(head);

    return 0;
}

/**
 * @brief  
 * @note   
 * @param  *list: 
 * @param  value: 
 * @retval 
 */
node *FindNode(node *list, int value)
{
    //TODO: create a func that returns a pointer to a node that contains a specific value
    return NULL;
}

/**
 * @brief  Creates a new node in HEAP setting the next and number values
 * @note   
 * @param  value: numeric data you want to place in the node
 * @retval 
 */
node *CreateNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->number = value;
    tmp->next = NULL;

    return tmp;
}

/**
 * @brief  
 * @note   
 * @param  *head: 
 * @retval None
 */
void PrintLinkedList(node *head)
{
    node *tmp = head;
    while(tmp != NULL)
    {
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }
}