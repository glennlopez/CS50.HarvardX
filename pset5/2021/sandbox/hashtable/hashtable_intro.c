#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void AddToHashtable(node *hashtable[], string value);

int main()
{
    /* Create empty array */
    node *tmp[10];
    for (int i = 0; i < 10; i++)
        tmp[i] = NULL;

    /* Create new nodes + Add nodes to Hashtable*/
    AddToHashtable(tmp, "Five");
    AddToHashtable(tmp, "Twelve5");
    AddToHashtable(tmp, "Four4");
    AddToHashtable(tmp, "One6");

    AddToHashtable(tmp, "One");
    AddToHashtable(tmp, "Zero");
    AddToHashtable(tmp, "Seven");
    AddToHashtable(tmp, "One Hundred1");


    /* Debug */
    for (int i = 0; i < 10; i++)
    {
        if (tmp[i] != NULL)
            printf("tmp[%i]->%s\n",i, tmp[i]->value);
    }
    printf("\n");

    printf("tmp[4]->next-> %s\n", tmp[4]->next->value);
    printf("tmp[4]->next-> %s\n", tmp[4]->next->next->value);
    printf("tmp[4]->next-> %s\n", tmp[4]->next->next->next->value);
    printf("\n");

    //printf("%i\n", QuickHash10("One Hundred1"));

    // TODO: containt this in a function
    // TODO: check if a specific string is in the Hashtable
        // if it is, return the address of the node
            // check if the correct address was returned
    string search = "One6";
    for (int i = 0; i < 10; i++)
    {
        if ( (tmp[i] != NULL) && (tmp[i]->value == search))
        {
            printf("\"%s\" found!\n", search);
            break; // <- this "breaks" the else if instruction below
        }

        //TODO: fix this - function does not seach through linked list

        /*
        else if ((tmp[i] != NULL) && (tmp[i]->value != search)) // <- this should be "if" not "else if" -- if there is break above
        {
            printf("Next->\n");
            tmp[i] = tmp[i]->next; // TODO: fix this
        }
        */
    }



    return 0;
}


/**
 * @brief  Add a string to an existing hashtable
 * @note   This will calculate the hash value of the string and palce it in a bucket
 * @param  *hashtable[]: Pointer to an existing hashtable
 * @param  value: String value to add to the hash table
 * @retval None
 */
void AddToHashtable(node *hashtable[], string value)
{
    int hashValue = QuickHash10(value);
    AddToBucket(&hashtable[hashValue], value);
}

/**
 * @brief  Add a string value to a linked list bucket
 * @note   
 * @param  *bucket: existing linked list
 * @param  value: String value to set the new node
 * @retval None
 */
void AddToBucket(node **bucket, string value)
{
    node *tmp = *bucket;

    /* Base case */
    if (*bucket == NULL)
        *bucket = NewNode(value);

    /* Recursive case */
    else
        AddToBucket(&tmp->next, value);
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
