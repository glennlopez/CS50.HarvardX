/* Insert a node in an existing Linked List */
// Video: https://www.youtube.com/watch?v=VOpjAHCee7c&t=701s

#include<stdio.h>
#include<stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

void PrintList(node *head);
void InsertNodeAfter(node *node_to_insert_after, node *new_node);
void InsertNodeAt(node **head, node *node_to_insert);
node *NewNode(int number);
node *FindNode(node *head, int value);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    /* 1. Create a Linked List using a loop */
    printf("Create a linked list using a loop:\n");
    for (int i = 1; i <= 4; i++)
    {
        tmp = NewNode(i);           // point the tmp pointer to the new node
        tmp->next = head;           // point the pointer to the next node to where *head is pointing
        InsertNodeAt(&head, tmp);   // insert the new node at the head
    }
    
    /* Show the linked list BEFORE inserting a node */
    PrintList(head);
    printf("\n");


    /* 2. Inserting a new node */
    printf("Insert a new node:\n");
    InsertNodeAt(&head, NewNode(123));
    InsertNodeAfter(FindNode(head, 4), NewNode(22));

    /* Show the linked list AFTER Inserting a new node*/
    PrintList(head);
    printf("\n");


    /* 3. Finding a specific value in the list */
    printf("Find a specific value in the linked list:\n");
    int usrNum = 100;
    tmp = FindNode(head, usrNum);
    if(tmp == NULL)
        printf("Data(%i) not found.\n", usrNum);
    else
        printf("Data Found: %i(%p) \n", tmp->data, tmp);
    printf("\n");

    
    /* 4. Inserting a new node after a specific value in the list */
    printf("Insert a new node after a specific value in the linked list:\n");
    InsertNodeAfter(FindNode(head, 3), NewNode(9999));

    /* Show the linked list AFTER Inserting a new node*/
    PrintList(head);


}

/**
 * @brief  
 * @note   
 * @param  *head: Pointer to head (begining) of the linked list
 * @param  value: Value to delete
 * @retval None
 */
void DeleteNode(node *head, int value)
{
    //TODO: create a function that deletes a specific node from a linked list

}

/**
 * @brief  Insert a node after a specified location in the linked
 * @note   
 * @param  *location: a pointer to where node_to_insert will be placed
 * @param  *node_to_insert: a pointer to a node to be inserted into the list
 * @retval None
 */
void InsertNodeAfter(node *location, node *node_to_insert)
{
    // point the next pointer of the new_node to where the next pointer of the node_to_insert_after is pointing to
    node_to_insert->next = location->next;

    // point the next pointer of node_to_insert_after to the new node
    location->next = node_to_insert;
}

/**
 * @brief  Insert a node at a location specified by a pointer
 * @note   
 * @param  **location: a pointer to where location is pointing to
 * @param  *node_to_insert: a pointer to node_to_insert
 * @retval 
 */
void InsertNodeAt(node **location, node *node_to_insert)
{
    // point the next pointer to where location is pointing to
    node_to_insert->next = *location;

    // point the location pointer to where node_to _insert is pointing to
    *location = node_to_insert;
}

/**
 * @brief  Find a node in a linked list with a specific value, and return its pointer.
 * @note   
 * @param  *head: Pointer to the begining of a linked list (where to start looking)
 * @param  value: Value of data in the linked list you are looking for
 * @retval Returns a pointer to the value found in the linked list. Returns NULL if value is not found.
 */
node *FindNode(node *head, int value)
{
    // use a temporary pointer and point it to where head is pointing
    node *tmp = head;

    // iterate through the linked list until a node is NULL
    while(tmp != NULL)
    {
        // if the node has the value, return a pointer to that node
        if(tmp->data == value) return tmp; 

        // set the tmp pointer to the next node (continue to the next node in the link)
        tmp = tmp->next;
    }
    return NULL; // return NULL when the list search completes without the value being found
}

/**
 * @brief  Displays the data values in the linked list on the console
 * @note   Prints to console
 * @param  *head: pointer to the linked list head
 * @retval None
 */
void PrintList(node *head)
{
    // create a temporary node pointer to use
    node *tmp = NULL;

    // point the temporary pointer to where *head is pointing
    tmp = head;

    // Iterate throught the nodes until the next node is NULL
    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);  // print the current node data
        tmp = tmp->next;            // set the current pointer to the next node pointer
    }
}

/**
 * @brief  Creates a newly allocated node in HEAP memory 
 * @note   
 * @param  number: Value to set the new node data
 * @retval returns the pointer to the newly allocated node
 */
node *NewNode(int number)
{
    // allocate memory in heap the size of node struct
    node *new_node = malloc(sizeof(node));

    // set the data using function parameters
    new_node->data = number;

    // set the next node NULL
    new_node->next = NULL;

    // return a pointer to the new node allocated in heap
    return new_node;
}