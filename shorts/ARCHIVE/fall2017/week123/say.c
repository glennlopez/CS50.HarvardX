#include<stdio.h>
#include<cs50.h>

void say(string s, int i);

int main(){
    
    printf("Say: ");
    string s = get_string();
    printf("How many times: ");
    int i = get_int();
    
    say(s, i);
    
    return 0;
}


void say(string s, int i){
    
    for(int j = 0; j < i; j++){
        printf("%s\n", s);
    }
}