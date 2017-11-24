#include <stdio.h>
#include <cs50.h>

//calculate length of string
int strsize(char *param){
    int i = 0;
    int count = 0;
    
    while(param[i] != '\0'){
        i++;
        count++;
    }
    
    return count;
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
    
    printf("&s[0]: %i\n", (int)&s[0]);
    printf("&s[1]: %i\n", (int)&s[1]);
    printf("&s[2]: %i\n", (int)&s[2]);
    printf("&s[last]: %i\n", (int)&s[strsize(s)-1]);
    printf("s[last]: %c\n", s[strsize(s)-1]);
    printf("strsize(s): %i\n", strsize(s));
    
    return 0;
}
