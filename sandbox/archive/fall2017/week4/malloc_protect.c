#include <stdio.h>
#include <cs50.h>

int main(){

    const int MAX_UNAME = 5;    //username limit
    int countUname = 0;

    char *uname = malloc(sizeof(char) * MAX_UNAME);
    if(uname == NULL){
        printf("Error - Not enough memory\n");
        return 1;
    }

    //get username
    printf("Username: ");
    char *tempUname = get_string();

    //count length of username
    for(int i = 0; tempUname[i] != '\0'; i++){
        countUname++;
    }

    //max username length check
    if(countUname > MAX_UNAME){
        printf("Error - Program quit. Username too long.\n");
        return 2;
    }
    else{
        for(int i = 0; i < MAX_UNAME; i++){
            uname[i] = tempUname[i];
        }
    }

    //print out username
    printf("uname[0-4]: ");
    for(int i = 0; i < MAX_UNAME; i++){
        printf("%c", uname[i]);
    }
    printf("\n");


    //free uname malloc
    free(uname);

    printf("\n");
    return 0;
}