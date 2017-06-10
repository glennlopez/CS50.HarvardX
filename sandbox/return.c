#include<stdio.h>
#include<cs50.h>

int multi(int paramX, int paramY);

int main(){
    
    //get usr input
    printf("First Number: ");
    int x = get_int();
    printf("Second Number: ");
    int y = get_int();
    
    //print output
    printf("%i x %i = %i\n", x, y, multi(x, y));
    
    return 0;
}

int multi(int paramX, int paramY){
    return paramX * paramY;
}