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
void FreeNodes(node *head);
void InsertNodeAtHead(node *node_to_insert, node **head);
void InsertNodeAfter(node *target_node, node *node_to_insert);
void DeleteNode(node *target);
node *NewNode(int value);
node *FindNode(int node_value, node *head);

int main()
{
    node *head = NULL;

    /* Create a bunch of nodes and link them together */
    for (int i = 1; i <= 7; i++)
        InsertNodeAtHead(NewNode(i), &head);

    /* Find a specific node and print out its struct contents */
    node *find = FindNode(7, head);
    if(find != NULL)
    {
        if (find->prev != NULL)
            printf("Target->prev: %i\n", find->prev->value);
        printf("Target: %i\n", find->value);
        if (find->next != NULL)
            printf("Target->next: %i\n", find->next->value);
    }

    /* Insert a node after a specific node in a linked list */
    //InsertNodeAfter(FindNode(7, head), NewNode(999));

    DeleteNode(FindNode(6, head));

    // Print Linked List
    PrintList(head);

    // Memory Management
    //FreeNodes(head);
}

/**
 * @brief  
 * @note   
 * @param  *target: 
 * @retval None
 */
void DeleteNode(node *target) 
{
    node *tmp = target;

    if(target != NULL)
    {
        // if deleting head
        if(target->prev == NULL)
        {
            target->next->prev = NULL;
            target = target->next;
        }
        else
            target->prev->next = target->next;

        if (target->next != NULL)
            target->next->prev = target->prev;
        
        // Memory management
        tmp = target;
        free(tmp);
    }
}


/**
 * @brief  Insert a new node at the begining of a linked list
 * @note   
 * @param  *node_to_insert: Pointer to node to insert into a linked list
 * @param  **head: Pointer to the begining of a linked list for the node to be inserted to
 * @retval None
 */
void InsertNodeAtHead(node *new_node, node **target)
{
    // Point the new_node's next pointer to where the target is currently pointing
    new_node->next = *target;

    // Only do the following if the head (target) is not NULL (if its NULL, the node wont have a target->next, target->prev, or target->value, and you will get a segfault)
    if (*target != NULL)
    {
        // Set the target's prev pointer to point at the new_nodes (target will be placed after the new_node after this loop iteration)
        (*target)->prev = new_node;
    }

    // Set the new_node's prev pointer to NULL  (because it will be the new head)
    new_node->prev = NULL;

    // Point the target to new_node (set the newly inserted node to be the head of the list)
    *target = new_node;
}

/**
 * @brief  Insert a node after a node with a specified data
 * @note   
 * @param  *target_node: A pointer to the target node to insert after
 * @param  *node_to_insert: A pointer to the node to insert
 * @retval None
 */
void InsertNodeAfter(node *target_node, node *node_to_insert)
{
    // set the node_to_insert->next pointer to the target_node's -> next pointer
    node_to_insert->next = target_node->next;

    // if the next node after the target node is not NULL
    if (node_to_insert->next != NULL)
        // link the next node's prev pointer to the target node
        node_to_insert->next->prev = target_node;

    // set the node_to_insert's prev pointer to point at the the address of the target node
    node_to_insert->prev = target_node;

    // set the target node's next pointer to point at the node to insert
    target_node->next = node_to_insert;
}

/**
 * @brief  Free the memory allocations in a linked list
 * @note   
 * @param  *head: Pointer to the linked list head
 * @retval None
 */
void FreeNodes(node *head) 
{
    node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;         // set the tmp pointer to head so we can free the node and be able to advance to the next node
        head = head->next;  // set the next pointer for the next loop iteration
        free(tmp);          // free the current node in the loop
    }
}

/**
 * @brief  Find a node with a specific node value/data
 * @note   
 * @param  node_value: Intiger value to find
 * @param  *head: Pointer to a linked list head
 * @retval 
 */
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

/**
 * @brief  Allocated memory in heap for a node-sized data
 * @note   
 * @param  value: Set the intiger value of the new nodes data
 * @retval Returns a pointer to the new node created in HEAP
 */
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

/**
 * @brief  Prints the linked list data on the console
 * @note   
 * @param  *head: Pointer to the linked list head
 * @retval None
 */
void PrintList(node *head)
{
    node * tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->value);
        tmp = tmp->next;
    }
}   