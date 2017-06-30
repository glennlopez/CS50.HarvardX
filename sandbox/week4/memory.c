#include<stdio.h>
#include<cs50.h>

int main(){
    
    
    printf(" Input: ");
    char *s = get_string();
    
    
    char *word = malloc(sizeof(s)); 
    

    for(int i = 0, n = sizeof(word); i < n; i++){
       word[i] = s[i];
    }
    
    
    printf("Output: ");
    for(int i = 0, n = sizeof(word); i < n; i++){
        printf("%c", word[i]);
    }
    
    free(word);
    
    int size_s = sizeof(s);
    printf("\n");
    printf("Size of s: %i\n", size_s);
    return 0;
}