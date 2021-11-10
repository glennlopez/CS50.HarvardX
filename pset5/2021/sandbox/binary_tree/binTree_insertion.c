#include <stdio.h>
#include <stdlib.h>

typedef struct treenode_struct
{
    int value;
    struct treenode_struct *left;
    struct treenode_struct *right;
}
treenode;

treenode *CreateLeaf(int val);
treenode *FindLeaf(int val, treenode *root);
void InsertNewLeaf(int val, treenode **root);

int main()
{
    /* Pre-Generated Nodes */
    treenode *root = NULL;
    treenode *leaf[7];
    for (int i = 0; i < 7; i++)
        leaf[i] = CreateLeaf((i + 1) * 10);


    
    /* Tree assembly */
    leaf[4 - 1]->left = leaf[2 - 1];
    leaf[4 - 1]->right = leaf[6 - 1];
    leaf[2 - 1]->left = leaf[1 - 1];
    leaf[2 - 1]->right = leaf[3 - 1];
    leaf[6 - 1]->left = leaf[5 - 1];
    leaf[6 - 1]->right = leaf[7 - 1];
    root = leaf[4 - 1];

    /* Insert a new leaf in the tree */
    InsertNewLeaf(25, &root);
    InsertNewLeaf(15, &root);
    InsertNewLeaf(59, &root);
    InsertNewLeaf(55, &root);
    InsertNewLeaf(41, &root);
    InsertNewLeaf(9, &root);
    InsertNewLeaf(20, &root);

    printf("\n");

    /* Search value in the tree */
    treenode *find = FindLeaf(55, root);
    if (find != NULL)
        printf("FindLeaf() returns: %i\n", find->value);

}

/**
 * @brief  
 * @note   
 * @param  val: 
 * @param  **root: 
 * @retval None
 */
void InsertNewLeaf(int val, treenode **root)
{
    treenode *tmp = *root;

    /* Base Case */
    if (tmp == NULL)
    {
        printf("Added new node.\n");
        *root = CreateLeaf(val);
    }

    /* Recursive Case */
    else if (val < tmp->value) 
    {
        printf("Adding: Go left.\n");
        InsertNewLeaf(val, &tmp->left);
    }
    else
    {
        printf("Adding: Go right.\n");
        InsertNewLeaf(val, &tmp->right);
    }
}

/**
 * @brief  Recursively seeks the tree for a specific node value
 * @note   
 * @param  val: Value to seek for in the binary tree
 * @param  *root: Pointer to the root of the tree
 * @retval Returns a pointer to the node with the specified value
 */
treenode *FindLeaf(int val, treenode *root)
{
    treenode *tmp = root; // Temporary pointer
    if (tmp != NULL)
    {
        /* Base case */
        if (tmp->value == val)
        {
            printf("Value %i found!\n", tmp->value);
            return tmp;
        }

        /* Recursive case */
        else if (val < tmp->value)
        {
            printf("Move: Left\n");
            return FindLeaf(val, tmp->left);
        }
        else
        {
            printf("Move: Right\n");
            return FindLeaf(val, tmp->right);
        }
    }

    else
    {
        printf("Value not found.\n");
    }

    return NULL;
}

/**
 * @brief  Allocates memory of size "treenode" to HEAP
 * @note   
 * @param  val: Integer value to set the new node
 * @retval Returns a pointer to the newly allocated memory in heap
 */
treenode *CreateLeaf(int val)
{
    treenode *tmp = malloc(sizeof(treenode));
    tmp->value = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}