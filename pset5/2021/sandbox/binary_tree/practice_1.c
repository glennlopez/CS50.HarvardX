#include <stdio.h>
#include <stdlib.h>

typedef struct treenode_struct
{
    int value;
    struct treenode_struct *left;
    struct treenode_struct *right;
}
treenode;

treenode *CreateNode(int value);
treenode *FindNode(int value, treenode *root);

int main()
{
    /* Nodes in Heap memory */
    treenode *n1 = CreateNode(11);
    treenode *n2 = CreateNode(22);
    treenode *n3 = CreateNode(33);
    treenode *n4 = CreateNode(44);
    treenode *n5 = CreateNode(55);
    treenode *n6 = CreateNode(66);
    treenode *n7 = CreateNode(77);

    /* Treenode assembly  */
    treenode *root = n4;
    n4->left = n2;
    n4->right = n6;
    n2->left = n1;
    n2->right = n3;
    n6->left = n5;
    n6->right = n7;

    /* Search for a value in the treenode */
    FindNode(55, root);


    return 1;
}

// create a tree node
treenode *CreateNode(int value)
{
    treenode *tmp = malloc(sizeof(treenode));
    tmp->value = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

/**
 * @brief  Recursively look for a value in the tree node and return its pointer when found.
 * @note   
 * @param  value: Integer value to look for in the treenode
 * @param  *root: Pointer to the root of the treenode
 * @retval Returns a pointer to the treenode 
 */
treenode *FindNode(int value, treenode *root)
{
    treenode *tmp = root;
    if (tmp != NULL)
    {
        /* base case */
        if (tmp->value == value)
        {
            printf("Move: Value %i was found.\n", tmp->value);
            return tmp;
        }

        else if (value < tmp->value)
        {
            // search value is lessthan the curent node value - go left
            printf("Move: Left\n");
            FindNode(value, tmp->left);
        }

        else
        {
            // search value is greaterthan the curent node value - go right
            printf("Move: Right\n");
            FindNode(value, tmp->right);
        }
    }

    else
    {
        printf("Value(%i) not found.\n", value);
    }

    return NULL; // return null if value was not found in the list
}

// free nodes in tree
void FreeNodes(treenode root)
{
    //TODO:
}