#include <stdio.h>
#include <stdlib.h>

//node datatype
typedef struct node_ptr
{
    int number;
    struct node_ptr *next;
}
node;

int main()
{
    node *list = NULL;  // list name
    node *n = NULL;     // node name

    // 1. allocate HEAP memory for a node
    // 2. set the nodes number value in the node
    // 3. set the nodes next pointer to NULL (for the for loop)
    // 4. point the newly created node to the linked list

    n = malloc(sizeof(node));
    n->number = 12;
    n->next = NULL;

    list = n;

    n = malloc(sizeof(node));
    n->number = 22;
    n->next = NULL;

    list->next = n;

    n = malloc(sizeof(node));
    (*n).number = 99;
    (*n).next = NULL;

    list->next->next = n;




    // display linked list
    for (node *tmp = list; list != NULL; list = list->next)
    {
        printf("%i\n", list->number);
    }


    return 0;
}