/* Insert a node in an existing Linked List */
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
node *InsertAtHead(node *head, node *node_to_insert);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    // create 4 nodes using a loop
    for (int i = 1; i <=4; i++)
    {
        tmp = NewNode(i);
        tmp->next = head;
        head = InsertAtHead(head, tmp); //head = tmp;
    }
    
    // print linked list before insert
    PrintList(head);
    printf("\n");

    // TODO: insert a new node
    

    // print linked list after insert
    PrintList(head);
}

/**
 * @brief  Insert a new node at the head of the LinkedList
 * @note   This function does not change the head
 * @param  *head: pointer to the linked list head
 * @param  *node_to_insert: pointer to the new node to insert
 * @retval Returns a pointer to the new node
 */
node *InsertAtHead(node *head, node *node_to_insert)
{
    // point the next pointer of the node_to_insert to the head
    node_to_insert->next = head;
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

    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
    }
}

/**
 * @brief  Creates a new linked list node allocated in HEAP memory.
 * @note   
 * @param  number: Intiger value to set inside of data
 * @retval returns the pointer to the newly allocated node
 */
node *NewNode(int number)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = number;
    new_node->next = NULL;

    return new_node;
}