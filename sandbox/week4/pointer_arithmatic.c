#include <stdio.h>
#include <cs50.h>
#include <string.h>

int count_char(char *);

int main(){

    //get user string
    char *uString = get_string();

    //transfer user string to heap memory
    char *mString = malloc(strlen(uString) + 1 * sizeof(char));
    for(int i = 0, n = strlen(uString); i < n; i++){

        //POINTER ARITHMATIC
        mString[i] = *(uString + i);
    }

    //print out string from heap memory
    for(int i = 0; mString[i] != '\0'; i++){
        
        //POINTER ARITHMATIC
        printf("%c", *(mString + i) );
    }
    printf("\n");


    return 0;
}


//count string subroutine
int count_char(char *param){    
    int count = 0;

    for(int i = 0; param[i] != '\0'; i++){
        count++;
    }

    return count;
}