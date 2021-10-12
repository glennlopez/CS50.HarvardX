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
    node *list = NULL;
    node *n = NULL;

    n = malloc(sizeof(node));
    n->number = 12;
    n->next = NULL;

    list = n;

    n = malloc(sizeof(node));
    n->number = 22;
    n->next = NULL;

    list->next = n;

    for (node *tmp = list; list != NULL; list = list->next)
    {
        printf("%i\n", list->number);
    }


    return 0;
}