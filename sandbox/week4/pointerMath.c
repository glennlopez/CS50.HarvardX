#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(){
    
    //get input string from user
    printf("Input: ");
    char *s = get_string();
    if(s == NULL){
        return 1;
    }
    
    //print string using pointer arithmatic
    printf("Output: ");
    for(int i = 0; s[i] != '\0'; i++){
        if(i == 0){
            //uppercase the first char
            s[i] = toupper(s[i]);
        }
        printf( "%c", *(s + i) );
    }
    printf("\n");
    
    return 0;
}