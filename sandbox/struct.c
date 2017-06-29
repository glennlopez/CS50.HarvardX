#include<stdio.h>
#include<cs50.h>

#define MAX_STUDENT 3

typedef struct{
    char *name;
    char *dorm;
} student;


int main(){
    
    student UoM[MAX_STUDENT];
    
    for(int i = 0; i < MAX_STUDENT; i++){
        printf("Name: ");
        UoM[i].name = get_string();
        printf("Dorm: ");
        UoM[i].dorm = get_string();
        printf("\n");
    }
    
    //this will add user inputs to a textfile
    FILE *file = fopen("test.txt", "a");
    if(file != NULL){
        for(int i = 0; i < MAX_STUDENT; i++){
            //printf("%s belongs to %s\n", UoM[i].name, UoM[i].dorm);
            fprintf(file, "%s belongs to %s\n", UoM[i].name, UoM[i].dorm);
        
        }
        fclose(file);
        
    }
    
    
    return 0;
}