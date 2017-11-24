#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void){
    
    printf("s: ");
    char *s = get_string();
    printf("s: %s\n", s);

    return 0;
}