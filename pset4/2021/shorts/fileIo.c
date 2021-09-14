#include <cs50.h>
#include <stdio.h>
#include <string.h>

// prototypes
int AppendToFile(void);
int ReadFromFile(void);
int WriteToFile(void);

int main()
{
    //AppendToFile();
    //ReadFromFile();
    WriteToFile();
}

// WRITE TO A NEW FILE
// fopen() fputc()
int WriteToFile()
{
    FILE *newfile = fopen("newfile.txt", "w");
    if(newfile == NULL)
    {
        return 1;
    }

    // todo: write to a new file

    return 0;
}



// READ FROM FILE EXAMPLE
// fopen() fgetc()
int ReadFromFile()
{
    FILE *csvfile = fopen("file.csv", "r");
    if(csvfile == NULL)
    {
        return 1;
    }

    // todo: read file
    char txt;
    while( (txt = fgetc(csvfile)) != EOF )
    {
        printf("%c", txt);
    }


    fclose(csvfile);
    return 0; // no error
}



// APPEND TO FILE EXAMPLE
// fopen() fprintf() fclose()
int AppendToFile()
{
    FILE *textfile = fopen("file.csv", "a"); // open a file and append to it
    if(textfile == NULL)
    {
        return 1;
    }

    // todo:  append a new person in the phonebook
    char *name = get_string("Name: ");
    char *phone = get_string("Number: ");

    fprintf(textfile, "%s, %s\n", name, phone);

    fclose(textfile);
    return 0;
}