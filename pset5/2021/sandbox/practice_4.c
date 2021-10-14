/* same as before except now use a FOR-LOOP to populate the lined list */

#include<stdio.h>
#include<stdlib.h>

typedef struct node_struct
{
    int num;
    struct node_struct *next;
}
node;

// prototypes
void PrintList(node *head);
node *CreateNode(int userNum);

int main()
{

    node *head = NULL;
    node *tmp = NULL;

    for (int i = 1; i <= 3; i++)
    {


    }

}


// func display nodes in linked list
void PrintList(node *head)
{
    node *tmp = head; // point a temp node to the head
    while (tmp != NULL)
    {
        printf("%i\n", tmp->num);
        tmp = tmp->next;    // set the tmp to the next node
    }
}

// func for creating a node
node *CreateNode(int userNum)
{
    node *new_node = malloc(sizeof(node));
    new_node->num = userNum;
    new_node->next = NULL;

    return new_node;
}