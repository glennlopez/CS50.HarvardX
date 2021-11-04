// https://cs50.harvard.edu/x/2021/shorts/singly_linked_lists/

#include <stdio.h>
#include <stdlib.h>

/* Scope:
 * [x] Create a linked list
 * [x] Search a linked list
 * [x] Insert a new node into a linked list
 * [ ] Delete a single element from the linked list
 * [x] Delete/Free the linked list nodes
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
void FreeListNodes(node *head);
void DeleteNode(int target_val, node *head);

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

    DeleteNode(5, head); //TODO: segfault deleting head or tail

    /* Print the linked list */
    PrintList(head);

    /* Memory Management */
    FreeListNodes(head);

}

void DeleteNode(int target_val, node *head)
{
    node *prevNode = NULL;

    while (head != NULL)
    {
        // Set the previous node pointer
        if ((head->next != NULL) && (head->next->value == target_val))      // IF: next node value has the target value
            prevNode = head;                                                // point the prevNode pointer to where head is currently pointing

        // Delete the target node
        if (head->value == target_val)
        {
            prevNode->next = head->next; // TODO: fix segfault
            free(head);
        }

        head = head->next;
    }

}


/**
 * @brief  
 * @note   
 * @param  *head: 
 * @retval None
 */
void FreeListNodes(node *head)
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
 * @brief  
 * @note   
 * @param  value: 
 * @param  *head: 
 * @retval 
 */
node *Find(int value, node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        if (tmp->value == value)
            return tmp;
    return NULL;
}

/**
 * @brief  
 * @note   
 * @param  *new_node: 
 * @param  **head: 
 * @retval None
 */
void Insert(node *new_node, node **head)
{
    new_node->next = *head;
    *head = new_node;
}

/**
 * @brief  
 * @note   
 * @param  *head: 
 * @retval None
 */
void PrintList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%i\n", tmp->value);
}

/**
 * @brief  
 * @note   
 * @param  value: 
 * @retval 
 */
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->value = value;
    return tmp;
}