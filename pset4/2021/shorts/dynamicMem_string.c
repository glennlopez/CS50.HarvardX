#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char *s = get_string("s-input: ");

    //char *t = s;
    char *t = malloc(strlen(s) + 1); // we add + 1 to include "\0" into the copy
    if(t == NULL)
    {
        return 1; //error code 1
    }

    // copy every char to a new string
    /*
    for(int i = 0; i < strlen(s); i++)
    {
        t[i] = s[i];
    }
    */
    strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("strlen(s): %lu\n", strlen(s));

    //free(t);


    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("\n");

    printf("sizeof(t): %lu\n\n", sizeof(t));

    //free(t);
}