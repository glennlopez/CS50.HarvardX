#include <stdio.h>
#include <stdlib.h>

#define string char *
typedef struct node_struct
{
    string value;
    struct node_struct *next;
}
node;

int QuickHash10(string name);
int StringLen(string s);
node *NewNode(string strVal);
void AddToBucket(node **bucket, string value);

int main()
{
    // TODO: linked list array

    /* Create empty array */
    node *tmp[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = NULL;

    /* Create new nodes */
    AddToBucket(&tmp[0], "one_a");
    AddToBucket(&tmp[0], "one_b");
    AddToBucket(&tmp[0], "one_c");

    AddToBucket(&tmp[1], "two_a");
    AddToBucket(&tmp[2], "three_a");

    /* Debug */
    for (int i = 0; i < 3; i++)
    {
        if (tmp[i] != NULL)
            printf("%s\n", tmp[i]->value);
    }

    printf("next-> %s\n", tmp[0]->next->value);
    printf("next-> %s\n", tmp[0]->next->next->value);


    return 0;
}

/**
 * @brief  
 * @note   
 * @param  *bucket: Array bucket
 * @param  value: String value to set the new node
 * @retval None
 */
void AddToBucket(node **bucket, string value)
{
    // THIS NEEDS TO BE RECURSIVE AND
    node *tmp = *bucket;

    /* Base case */
    if (*bucket == NULL)
    {
        *bucket = NewNode(value);
    }

    /* Recursive case */
    else
    {
        AddToBucket(&tmp->next, value);
    }

}


/**
 * @brief  Malloc a new node in HEAP memory of size node
 * @note   
 * @param  strVal: 
 * @retval returns a pointer to the newly generated node
 */
node *NewNode(string strVal)
{
    node *tmp = malloc(sizeof(node));
    tmp->value = strVal;
    tmp->next = NULL;
    return tmp;
}

/**
 * @brief  Generates an int hash
 * @note   
 * @param  name: string to hash out
 * @param  modval: mod value to limit the max value hashed
 * @retval Returns the int hash value
 */
int QuickHash10(string name)
{
    // get string length
    int nameLen = StringLen(name);
    int hashval = 0;

    for (int i = 0; i < nameLen; i++)
    {
        hashval += name[i];
    }
    
    return hashval % 10;
}

/**
 * @brief  Count the characters in the string
 * @note   
 * @param  s: Accepts a string or char *
 * @retval Returns an int value for the char count
 */
int StringLen(string s)
{
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}
