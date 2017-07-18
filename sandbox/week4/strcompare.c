#include <stdio.h>
#include <cs50.h>

int main(){
    //test string
    char t[] = {'G','L','E','N','N','\0'};  //<-- notice the null char
    
    //get input from user
    printf("Name: ");
    char *s = get_string();
    
    //print user string
    int i = 0;
    while(s[i] != '\0'){
        printf("%c",s[i]);
        i++;
    }
    printf("\n");
    
    //print test string
    i = 0;
    while(t[i] != '\0'){
        printf("%c",t[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}
