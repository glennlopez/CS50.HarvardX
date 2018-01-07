#include<stdio.h>
#include<cs50.h>

int main(){
    
    for(int i = 0; i <= 10; i++){
        printf("#\n");
        eprintf("i is now %i\n", i);    //error print format
    }
    
    return 0;
}