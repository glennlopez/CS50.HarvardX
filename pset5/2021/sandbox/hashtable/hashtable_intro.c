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
node *Search(string item, node *hashtable[]);

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

    node *test_found = Search("Twelve5", tmp);
    if(test_found != NULL)
        printf("test_found = %s\n",test_found->value);
    


    return 0;
}

/**
 * @brief  Recursively search a linked list for a specific item
 * @note   This is used in the node *Search() function
 * @param  item: 
 * @param  *linkedList: 
 * @retval 
 */
node *Seek(string item, node *linkedList)
{
    /* Base case */
    // if item is found, return it

    /* Recursive case */
    // if item is not found, 
}


/**
 * @brief  Looks for a specified item in a hashtable
 * @note   
 * @param  item: String value
 * @param  *hashtable[]: Pointer to a hash table array to look through
 * @retval Returns a pointer to the item found in the hash table
 */
node *Search(string item, node *hashtable[])
{
    node *found = NULL;

    for (int i = 0; i < 10; i++)
    {
        /*
        //TODO: searching through linked list should be RECURSIVE 
        if ((hashtable[i] != NULL) && (hashtable[i]->value == item))
        {
            printf("\"%s\" found!\n", item);
            found = hashtable[i];
            break; // <- this "breaks" the else if instruction below
        }

        //TODO: fix this - function does not seach through linked list
        
        else if ((hashtable[i] != NULL) && (hashtable[i]->value != item)) // <- this should be "if" not "else if" -- if there is break above
        {
            hashtable[i] = hashtable[i]->next; // TODO: fix this
        }

        /*

        /* TODO: USE node *Seek() */




        
    }

    return found;
}


/**
 * @brief  Add a string to an existing hashtable
 * @note   This will calculate the hash value of the string and place it in a bucket
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
