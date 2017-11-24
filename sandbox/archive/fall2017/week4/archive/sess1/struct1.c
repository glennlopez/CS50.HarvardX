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
        
    }
    
    //print out student name
    for(int i = 0, n = strlen(s); i < n; i++){
        printf("%c", *(s+i));
        
    }
    
    
    //debug output
    int size_s = strlen(s);
    printf("Size of s: %i\n", size_s);
    printf("\n");
    return 0;
}