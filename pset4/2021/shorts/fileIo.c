#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *textfile = fopen("file.csv", "a"); // open a file and append to it
    if(textfile == NULL)
    {
        return 1;
    }

    // todo:  add a new person in the phonebook
    char *name = get_string("Name: ");
    char *phone = get_string("Number: ");

    fprintf(textfile, "%s, %s\n", name, phone);
    fclose(textfile);

}