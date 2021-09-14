#include <cs50.h>
#include <stdio.h>
#include <string.h>

// prototypes
int AppendToFile(void);
int ReadFromFile(void);
int WriteToFile(void);
int CopyFile(void);

int main()
{
    //AppendToFile();
    //ReadFromFile();
    //WriteToFile();
    CopyFile();

}


// COPY A FILE
// fopen() fgetc() fputc() fclose()
int CopyFile()
{

    // Open filepointer for reading
    FILE *source = fopen("file.csv", "r");
    if(source == NULL)
    {
        return 1;
    }

    // Open filepointer for writing
    FILE *copy = fopen("newfile.txt", "w");
    if(copy == NULL)
    {
        return 1;
    }

    // Read the source file and copy its contents to a new file
    char ch;
    while( (ch = fgetc(source)) != EOF )
    {
        //printf("%c", ch); // console debug
        fputc(ch, copy);
    }


    fclose(source);
    fclose(copy);
    return 0;
}




// WRITE A CHAR TO A NEW FILE
// fopen() fputc()
int WriteToFile()
{
    FILE *newfile = fopen("newfile.txt", "w");
    if(newfile == NULL)
    {
        return 1;
    }

    // todo: write to a new file
    fputc('C', newfile);

    fclose(newfile);
    return 0;
}



// READ CHARs FROM A FILE
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



// APPEND STRINGS TO A FILE
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