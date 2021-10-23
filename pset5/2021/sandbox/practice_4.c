/* Practice List
 * [x] Print a linked list
 * [x] Create a new node
 * [ ] Find a node
 * [ ] Insert a node after a value
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int num;
    struct node_struct *next;
}
node;

node *NewNode(int value);
void ShowLinkedList(node *linked_list);
void InsertNode(node *node_to_insert, node **pointer_to_list);
node *FindNode(node *linked_list, int node_value);

int main ()
{
    node *numberList = NULL;

    // Generate a bunch of nodes using a loop
    for (int i = 1; i <= 5; i++)
        InsertNode(NewNode(i), &numberList); //TODO: fix memory leak

    // Debug
    ShowLinkedList(numberList);


    // Memory management
    free(numberList);

}

/**
 * @brief  Malloc a new node in HEAP
 * @note   
 * @param  value: Value to set the node number
 * @retval Returns a pointer to the created node in HEAP
 */
node *NewNode(int value)
{
    node *tmp = malloc(sizeof(node));
    tmp->num = value;
    tmp->next = NULL;

    return tmp;
}

/**
 * @brief  Insert
 * @note   
 * @param  *node_to_insert: 
 * @param  **pointer_to_list: 
 * @retval None
 */
void InsertNode(node *node_to_insert, node **pointer_to_list) //TODO: understand how this works (**po)
{
    node_to_insert->next = *pointer_to_list;
    *pointer_to_list = node_to_insert;
}

/**
 * @brief  
 * @note   
 * @param  *linked_list: 
 * @retval None
 */
void ShowLinkedList(node *linked_list)
{
    node *tmp = linked_list;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->num);
        tmp = tmp->next;
    }
}

/**
 * @brief  
 * @note   
 * @param  *linked_list: 
 * @param  node_value: 
 * @retval 
 */
node *FindNode(node *linked_list, int node_value)
{
    node *tmp = NULL;
    tmp = linked_list;

    while (tmp != NULL)
    {
        if (tmp->num == node_value)
            return tmp;
        tmp = tmp->next;
    }

    return tmp;
}

