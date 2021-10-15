#include <stdio.h>
#include <stdlib.h>

// node struct
typedef struct nodestruct
{
    int num;
    struct nodestruct *next;
}
node;

node *CreateNode(int usrNum);
void PrintList(node *head);

int main()
{
    node *head = NULL;
    node *tmp = NULL;

    // create a new node using the func
    /*
    tmp = CreateNode(100);
    head = tmp;

    tmp = CreateNode(90);
    tmp->next = head;
    head = tmp;

    tmp = CreateNode(80);
    tmp->next = head;
    head = tmp;
    */

    tmp = CreateNode(1);
    head = tmp;

    tmp = CreateNode(2);
    head->next = tmp;

    tmp = CreateNode(3);
    head->next->next = tmp;

    tmp = CreateNode(4);
    head->next->next->next = tmp;

    // read the linked list
    PrintList(head);


    return 0;
}


// Node reader
void PrintList(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%i\n", tmp->num);
        tmp = tmp->next;
    }
}


// Node creator function
node *CreateNode(int usrNum)
{
    // allocate a new node using malloc (create a new node in HEAP memory)
    node *new_node = malloc(sizeof(node));

    // set user argument value to the new node
    (*new_node).num = usrNum;
    new_node->next = NULL;

    // return the new node
    return new_node;
}