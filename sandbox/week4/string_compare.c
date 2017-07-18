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
    //test string
    char t[] = {'G','L','E','N','N','\0'};  //<-- notice the null char
    
    //get input from user
    printf("User Input: ");
    char *s = get_string();
    
    //print user string
    printf("s: ");
    int i = 0;
    while(s[i] != '\0'){
        printf("%c",s[i]);
        i++;
    }
    printf("\n");
    
    //print test string
    printf("t: ");
    i = 0;
    while(t[i] != '\0'){
        printf("%c",t[i]);
        i++;
    }
    printf("\n");
    
    printf("Result: %i\n", (int)string_compare(s,t));
    printf("&s[0]: %i\n", (int)&s[0]);
    printf("&s[1]: %i\n", (int)&s[1]);    
    printf("&t[0]: %i\n", (int)&t[0]);
    printf("&t[1]: %i\n", (int)&t[1]);

    
    return 0;
}
