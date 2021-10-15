#include <stdio.h>
#include <stdlib.h>

// node struct
typedef struct node_ptr
{
    int number;
    struct node_ptr *next;
}
node;

// prototypes
void PrintLinkedList(node *head);


/* Manual linking lists using pointers (no HEAP) */


int main()
{
    node n1, n2, n3;
    node *head;

    n1.number = 99;
    n2.number = 98;
    n3.number = 97;

    // linking
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    PrintLinkedList(head);


    return 0;
}

void PrintLinkedList(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        // print the number value in the node
        printf("%i\n", (*temp).number);

        // update the list
        temp = (*temp).next;
        
    }
}