/* Insert a node in an existing Linked List */
//https://www.youtube.com/watch?v=VOpjAHCee7c&t=701s

#include<stdio.h>
#include<stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

node *NewNode(int number);
void PrintList(node *head);
node *InsertNodeAt(node **head, node *node_to_insert);
node *FindNode(node *head, int value);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    // create 4 nodes using a loop
    for (int i = 1; i <= 4; i++)
    {
        tmp = NewNode(i);
        tmp->next = head;
        InsertNodeAt(&head, tmp); //head = tmp;
    }
    
    // print linked list before insert
    PrintList(head);
    printf("\n");

    // TODO: insert a new node
    InsertNodeAt(&head, NewNode(99));
    InsertNodeAt(&head, NewNode(77));
    InsertNodeAt(&head, NewNode(123));
    

    // print linked list after insert
    PrintList(head);

    //TODO: find a value in the list
    int usrNum = 123;
    tmp = FindNode(head, usrNum);
    if(tmp == NULL)
        printf("Data(%i) not found.\n", usrNum);
    else
        printf("Data Found: %i(%p) \n", tmp->data, tmp);
    
}

/**
 * @brief  Find a specific value in the linked list
 * @note   
 * @param  *head: Pointer to the head of the linked list
 * @param  value: Item in the list you are looking for
 * @retval Returns a pointer to the value 
 */
node *FindNode(node *head, int value)
{
    //TODO: understand how this works

    node *tmp = head;

    // Iterate through the list until list is NULL
    while(tmp != NULL)
    {
        // return a pointer to the node value if found
        if(tmp->data == value) return tmp; 
        tmp = tmp->next;    // if not found, check the next node
    }
    return NULL;    // if value is not found, return NULL
}

/**
 * @brief  Insert a node at the head of the list
 * @note   
 * @param  **head: Pass a pointer to a pointer
 * @param  *node_to_insert: 
 * @retval 
 */
node *InsertNodeAt(node **head, node *node_to_insert)
{
    //TODO: understand how this works

    // point the next pointer where the head is pointing
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert; // return the address of the new node
}

/**
 * @brief  Displays the data values in the linked list on the console
 * @note   Prints to console
 * @param  *head: pointer to the linked list head
 * @retval None
 */
void PrintList(node *head)
{
    node *tmp = NULL;
    tmp = head;

    // Print the data while the current node is not NULL
    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
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
    node *new_node = malloc(sizeof(node));
    new_node->data = number;
    new_node->next = NULL;

    return new_node;
}