// https://cs50.harvard.edu/x/2021/shorts/singly_linked_lists/

#include <stdio.h>
#include <stdlib.h>

/* Scope:
 * [x] Create a linked list
 * [x] Search a linked list
 * [x] Insert a new node into a linked list
 * [x] Delete a single element from the linked list
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
void DeleteNode(int target_val, node **head);

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

    DeleteNode(5, &head);

    /* Print the linked list */
    PrintList(head);

    /* Memory Management */
    FreeListNodes(head);

}

/**
 * @brief  Delete node with specific value in the linked list
 * @note   
 * @param  target_val: Node with the value to deallocate and delete
 * @param  **head: Pointer to the linked list
 * @retval None
 */
void DeleteNode(int target_val, node **head)
{
    node *prevNode = NULL;  // keeps track of the target nodes prev node 
    node *tmp = NULL;       // temporary nullpointer 
    node *cur_node = *head;     // copy of the head pointer

    while(cur_node != NULL)
    {
        // Set the previous node pointer
        if ((cur_node->next != NULL) && (cur_node->next->value == target_val))      // IF: next node value has the target value
            prevNode = cur_node;                                                // point the prevNode pointer to where head is currently pointing

        // Delete the target node
        if (cur_node->value == target_val && prevNode != NULL)
        {
            if (cur_node->next != NULL)
            {
                prevNode->next = cur_node->next;
                free(cur_node);
            }

            // properly remove and de-allocate tail node
            if (cur_node->next == NULL)
            {
                free(prevNode->next);
                prevNode->next = NULL;
            }
        }

        // properly remove and de-allocate the head node
        if (cur_node->value == target_val && prevNode == NULL)
        {
            tmp = *head;
            *head = (*head)->next;
            free(tmp);
            break; // O(1) operation: no need interate over the entire list if target is head
        }

        cur_node = cur_node->next;
    }

}


/**
 * @brief  De-allocate the linked list nodes
 * @note   
 * @param  *head: Pointer to the head of the linked list
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
 * @brief  Find a node in a linked list with a specific node value
 * @note   
 * @param  value: Value of the target node you wish to find
 * @param  *head: Pointer to the head of the linked list
 * @retval Returns a pointer to the node with a specific value you are looking for
 */
node *Find(int value, node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        if (tmp->value == value)
            return tmp;
    return NULL;
}

/**
 * @brief  Inserts a new node at the begining of a linked list
 * @note   
 * @param  *new_node: Pointer to a new node
 * @param  **head: Pointer to the list
 * @retval None
 */
void Insert(node *new_node, node **head)
{
    new_node->next = *head;
    *head = new_node;
}

/**
 * @brief  Prints the node values to the console
 * @note   
 * @param  *head: Pointer to the linked list
 * @retval None
 */
void PrintList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        printf("%i\n", tmp->value);
}

/**
 * @brief  Allocate a new node in heap memory
 * @note   
 * @param  value: Value to assign in the node value
 * @retval Returns a pointer to the newly allocated node in heap
 */
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->next = NULL;
    tmp->value = value;
    return tmp;
}