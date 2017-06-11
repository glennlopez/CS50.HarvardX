#include<stdio.h>
#include<cs50.h>

void print_greeting(void);
void print_name(string s);

int main(){
    
    print_greeting();
    string uName = get_string();
    print_name(uName);
    
    return 0;
}

void print_greeting(void){
    printf("Whats your name: ");
}

void print_name(string s){
    printf("Hello %s\n",s);
}