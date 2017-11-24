#include<stdio.h>
#include<cs50.h>
#include<string.h>

//valgrind ./struct2

typedef struct{
    int age;
    int id;
    char name[10];
} student;



int main(){
    
    //Create struct on the HEAP
    student *bob = malloc(sizeof(student));
    
    //get user input
    printf("Name: ");
    char *s = get_string();
    
    //Set struct
    (*bob).age = 12;
    (*bob).id = 1234;
    
    
    //copy user input to HEAP memory struct
    for(int i = 0, n = strlen(s); i < n; i++){
        (*bob).name[i] = *(s + i);
    }
    
    
    //print array
    printf("Bob name: ");
    for(int i = 0, n = strlen(s); i < n; i++){
        printf("%c", bob->name[i]);
    }
    printf("\n");
    


    printf("Bob age: %i\n", bob->age);
    printf("\n");
    
    free(bob);
    return 0;
}