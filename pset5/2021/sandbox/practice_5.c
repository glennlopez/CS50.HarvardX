
#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

void PrintList(node *head);
void FreeNodes(node* head);

int main() 
{
    node *list = NULL;
    node *tmp = NULL;

    tmp = malloc(sizeof(node));
    tmp->data = 10;
    tmp->next = list;
    list = tmp;

    tmp = malloc(sizeof(node));
    tmp->data = 20;
    tmp->next = list;
    list = tmp;

    tmp = malloc(sizeof(node));
    tmp->data = 33;
    tmp->next = list;
    list = tmp;

    

    PrintList(list);

    //MEMORY MANAGEMENT
    FreeNodes(list);

    return 0;
}

/**
 * @brief  Free allocated memory in HEAP, used in linked list
 * @note   
 * @param  head: Pointer to the start of the linked list
 * @retval None
 */
void FreeNodes(node* head)
{
    // temp pointer for reference
    node* tmp = NULL;

    // iterate through the linked list until a NULL pointer is found
    while (head != NULL)
    {
       tmp = head;          // point the temp pointer to the head of the linked list pointer
       head = head->next;   // advance the head pointer to the next node
       free(tmp);           // free the current nodes memory
    }

}

/**
 * @brief  Print the contents of the linked list on the console
 * @note   
 * @param  *head: 
 * @retval None
 */
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->data);
        tmp = tmp->next;
    }
    
}