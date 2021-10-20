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
 * [ ] Insert a node after a value
 * [ ] Insert a node at a specific pointer
 * [ ] Delete a node
 */

void PrintLinkedList(node *head);
node *CreateNode(int value);
node *FindNode(node *list, int value);

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

    // debug FindNode()
    node *test = FindNode(head, 2);
    if (test == NULL)
    {
        printf("test pointer returned NULL\n");
        return 1;
    }
    printf("Found (test->number): %i\n", test->number);

    return 0;
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