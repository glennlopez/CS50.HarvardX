#include <stdio.h>
#include <cs50.h>

/*
    Creates a duplicate file accepting 1 paramater (the file name)
*/

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Error: Invalid param!\n");
        return 1;
    }

    //get size of argv[1]
    int argv_size = 0;
    for(int i = 0; argv[1][i] != '\0'; i++){
        argv_size++;
    }

    //allocate some heap memory for filename
    char *filename = malloc( (sizeof(char) * argv_size) + 2);

    //generate a new filename for the duplicate file
    char fileCount = '0';
    for(int i = 0; argv[1][i] != '\0'; i++){
        filename[i] = argv[1][i];
        //FIXME: make this proper
        if(filename[i] == '.'){
            filename[i-1] = fileCount;
            fileCount++;
        }
    }

    FILE *originalFile = fopen(argv[1], "r");
    FILE *copiedFile = fopen(filename, "w");

    char ch;
    while( (ch = fgetc(originalFile)) != EOF ){
        fputc(ch, copiedFile);
    }

    fclose(originalFile);
    fclose(copiedFile);





    //debug out
    for(int i = 0; filename[i] != '\0'; i++){
        printf("%c", filename[i]);
    }


    printf("\n");   //new line
    return 0;
}