#include<stdio.h>
#include<cs50.h>

int get_negative(void);

int main(){
    
    int i = get_negative();
    printf("%i is a negative number\n", i);
    
    return 0;
}

int get_negative(void){int n = 9999;
    do{
    
    printf("Number: ");
    n = get_int();
        
    }while(n >= 0);
    return n;
}