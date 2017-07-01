#include<stdio.h>
#include<cs50.h>
#include<string.h>

struct student{
  char *name;
  int age;
};



int main(){
    
    //create struct on the HEAP
    struct student *biology = malloc(sizeof(struct student));
    
    //get student name
    printf("Student Name: ");
    char *s = get_string();
    
    //alocate memory to HEAP for student name
    char *name = malloc(strlen(s));
    
    //set INT on struck in HEAP
    (*biology).age = 12;
    
    //copy name from STACK to HEAP
    for(int i = 0, n = strlen(s); i < n; i++){
        (*biology).name[i] = s[i];
        *(name + i) = *(s + i);
        *(s + i) = '?'; //debug
    }
    
    
    //print out student name from HEAP 
    printf("Heap: ");
    for(int i = 0, n = strlen(name); i < n; i++){
        printf("%c", *(name+i));
    }
    printf("\n");
    
    //print out student name from STACK 
    printf("Stack: ");
    for(int i = 0, n = strlen(name); i < n; i++){
        printf("%c", *(s+i));
    }
    printf("\n");
    
    
    //debug output
    printf("Size of s: %lu\n", strlen(s));
    printf("Size of name: %lu\n", strlen(name));
    
    printf("Struct age: %i\n", (*biology).age);
    
    printf("\n");
    return 0;
}