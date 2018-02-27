#include<stdio.h>
#include<cs50.h>
bool is_rest(string);

int main(void){
    string s = get_string("String: ");

    printf("is_rest: %i", is_rest(s));

    printf("\n");
    return 0; 
} 





/* SUBROUTINES */
// Determines whether a string represents a rest
bool is_rest(string s){
    
    //count the number of characters in the string
    int counter = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] != '\0'){
            counter++;
        }
    }

    //checks for blank string
    if(counter <= 0){
        return 1;
    }
    else{
        return 0;
    }
}