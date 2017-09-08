#include<stdio.h>
#include<cs50.h>
#include<string.h>



int main(){
    
    //get student name
    printf("Student Name: ");
    char *s = get_string();
    
    //alocate memory to HEAP for student name
    char *name = malloc(strlen(s));
    
    //copy name from STACK to HEAP
    for(int i = 0, n = strlen(s); i < n; i++){
        *(name + i) = *(s + i);
        *(s + i) = '?';
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
    printf("\n");
    return 0;
}