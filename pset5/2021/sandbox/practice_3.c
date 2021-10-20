#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int number;
    struct node_struct *next;
}
node;

/* Practice List
 * [x] Print a linked list
 * [x] Create a new node
 * [x] Find a new node
 * [x] Insert a node after a value
 * [ ] Insert a node at a specific pointer
 * [ ] Delete a node
 */

void PrintLinkedList(node *head);
node *CreateNode(int value);
node *FindNode(node *list, int value);
void InsertNodeAfter(node *target_location, node *node_to_insert);

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
 * @brief  Insert a new node after a specified node in a linked list
 * @note   
 * @param  *target_location: Pointer to where you want to insert the node after
 * @param  *node_to_insert: Pointer to a node you wish to insert
 * @retval None
 */
void InsertNodeAfter(node *target_location, node *node_to_insert)
{
    node_to_insert->next = target_location->next;
    target_location->next = node_to_insert;
}

/**
 * @brief  Find a node with a specified value
 * @note   
 * @param  *list: Pointer to the head of the linked list you wish to search through
 * @param  value: Integer value you are looking for in the linked list
 * @retval Pointer to a node containing the value (null if not found)
 */
node *FindNode(node *list, int value)
{
    node *target = NULL;
    while (list != NULL)
    {
        if (list->number == value)
            target = list;

        // iterate to the next node in the list
        list = list->next;
    }
    
    return target;
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
 * @brief  Prints the content of the linked list in the console starting at the head
 * @note   
 * @param  *head: Pointer to a linked list starting at the head of the list
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