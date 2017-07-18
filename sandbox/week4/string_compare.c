#include <stdio.h>
#include <cs50.h>

//compare strings (0 if not diffrent)
bool string_compare(char *first, char *second){ int i;
    
    //compare if size is the same first
    int count_first = 0;
    i = 0;
    while(first[i] != '\0'){    //count *first
        count_first++;
        i++;
    }
    int count_second = 0;
    i = 0;
    while(second[i] != '\0'){    //count *second
        count_second++;
        i++;
    }
    
    if(count_first != count_second){
        return 1;
    }
    
    //compare each char
    for(i = 0; i < count_second; i++){
        if(first[i] != second[i]){
            return 1;
        }
    }
    
    return 0;
}


int main(){
    
    //get input from user
    printf("User Input 1: ");
    char *s = get_string();
    printf("User Input 2: ");
    char *t = get_string();
    
    //print results
    printf("Result: %i ", (int)string_compare(s,t));
    if(!(string_compare(s,t))){
        printf("(same)\n");
    }
    else{
        printf("(not the same)\n");
    }

    
    return 0;
}
