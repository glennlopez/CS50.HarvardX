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

    // copy every char to a new string
    for(int i = 0; i < strlen(s); i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("sizeof(s): %lu\n", strlen(s));


    printf("s: %s\n", s);
    printf("t: %s\n", t);
}