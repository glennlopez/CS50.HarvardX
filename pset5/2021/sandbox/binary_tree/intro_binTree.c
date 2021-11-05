//https://www.youtube.com/watch?v=UbhlOk7vjVY

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode_struct
{
    int value;
    struct treenode_struct *left;
    struct treenode_struct *right;
}
treenode;

treenode *CreateTreenode(int value);
treenode *LookFor(int value, treenode *root);

int main()
{
    /* Create the treenodes */
    treenode *root = NULL;
    treenode *n1 = CreateTreenode(11);
    treenode *n2 = CreateTreenode(22);
    treenode *n3 = CreateTreenode(33);
    treenode *n4 = CreateTreenode(44);
    treenode *n5 = CreateTreenode(55);
    treenode *n6 = CreateTreenode(66);
    treenode *n7 = CreateTreenode(77);

    /* Link the treenodes */
    n4->left = n2;
    n4->right = n6;
    n2->left = n1;
    n2->right = n3;
    n6->left = n5;
    n6->right = n7;

    root = n4;

    /* Print the treenodes */

    /* Traverse into a treenode looking for a value */
    int value = 58;
    treenode *tmpNum = LookFor(value, root);
    if (tmpNum != NULL)
        printf("LookFor(%i, root) returned: %i\n", value, tmpNum->value);

    /* Memory Management */
    free(n1); free(n2); free(n3); free(n4); free(n5); free(n6); free(n7);

}

/**
 * @brief  
 * @note   
 * @param  value: 
 * @param  *root: 
 * @retval 
 */
treenode *LookFor(int value, treenode *root)
{
    treenode *tmp = root;
    if (tmp != NULL)
    {
        /* Base case */
        if (tmp->value == value)
        {
           printf("%i was found!\n", value);
            return tmp;
        }

        /* Recursive Case */
        else if (value < tmp->value)
        {
            // less - go left
            printf("Move: Left\n");
            LookFor(value, tmp->left);
        }

        else 
        {
            // greater - go right
            printf("Move: Right\n");
            LookFor(value, tmp->right);
        }
    }

    else
        printf("%i Not found in tree.\n", value);

    return NULL;
}

/**
 * @brief  Allocate a new treenode in heap
 * @note   
 * @param  value: Intiger value of the treenode
 * @retval Returns a pointer to the newly created treenode
 */
treenode *CreateTreenode(int value)
{
    treenode *node = malloc(sizeof(treenode));
    if (node != NULL)
    {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}