#include<stdio.h>
#include<cs50.h>

int main(){
    
    printf("%i <-- 1/10 in int datatype\n", 1/10); //<--- is the same as below
    printf("%f <-- 1/10 in float datatype\n", 1/(float)10);
    
    printf("\n");
    
    
    printf("%.30f <-- 1/10 in 30 decimal places (float datatype)\n", 1/(float)10); //.10f <-- gives 10 decimal points
    
    return 0;
}