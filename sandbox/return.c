#include<stdio.h>
#include<cs50.h>

int adder(int paramX, int paramY);

int main(){
    
    int x = 10;
    int y = 20;
    int z = adder(x, y);
    
    printf("%i + %i = %i\n", x, y, z);
    
    return 0;
}

int adder(int paramX, int paramY){
    return paramX + paramY;
}