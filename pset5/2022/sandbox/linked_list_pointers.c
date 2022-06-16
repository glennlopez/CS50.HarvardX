#include <stdio.h>
#include <stdlib.h>


// node datatype
typedef struct node_struct
{
    int data;
    struct node_struct *next;
}
node;

int main ()
{
    // empty null pointers
    node *head = NULL;
    node *tmp = NULL;

    // Link 0
    tmp = malloc(sizeof(node));
    tmp->data = 100;
    tmp->next = NULL;

    head = tmp;

    // Link 1
    tmp = malloc(sizeof(node));
    tmp->data = 111;
    tmp->next = NULL;

    head->next = tmp;

    // Link 2
    tmp = malloc(sizeof(node));
    tmp->data = 222;
    tmp->next = NULL;

    head->next->next = tmp;

    // Link 3
    tmp = malloc(sizeof(node));
    tmp->data = 333;
    tmp->next = NULL;

    head->next->next->next = tmp;

    /*
    printf("link 0: %i \n", head->data);
    printf("link 1: %i \n", head->next->data);
    printf("link 2: %i \n", head->next->next->data);
    printf("link 3: %i \n", head->next->next->next->data);
    */


    // ittirate through the linked list
    node *loop = NULL;
    do
    {
        loop = head;
        printf("link: %i\n", loop->data);
        head = loop->next;
    }
    while(loop->next != NULL);


    return 0;
}