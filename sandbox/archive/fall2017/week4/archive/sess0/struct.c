#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct{
    char* name;
    char* dorm;
} student;

int main(){
    
    student glenn;
    
    glenn.name = "Glenn Lopez";
    glenn.dorm = "Walker";
    
    printf("Name: %s\n", glenn.name);
    printf("Dorm: ");
    for(int i = 0, n = strlen(glenn.dorm); i < n; i++){
        printf("%c", glenn.dorm[i]);
    }
    printf("\n");
    
    return 0;
}