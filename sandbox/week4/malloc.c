#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    //get user input
    printf("Input: ");
    char *s = get_string();
    
    //allocate dynamic memory
    char *t = malloc( (strlen(s) + 1) * sizeof(char) );
    if(t == NULL){
        return 1;
    }
    
    //copy content in static memory to dynamic memory
    for(int i = 0, n = strlen(s) + 1; i < n; i++){
        t[i] = s[i];
        if(i == 0){
            t[i] = toupper(t[i]);
        }
    }
    
    //print user input
    printf("Output: ");
    for(int i = 0; t[i] != '\0'; i++){
        printf("%c",t[i]);
    }
    printf("\n");
    
    return 0;
}
