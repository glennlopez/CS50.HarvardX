#include<cs50.h>
#include<stdio.h>

int main(){
    
    printf("1 byte = 8 bits\n\n");
    
    printf("bool is %lu byte\n", sizeof(bool));
    printf("char is %lu byte\n", sizeof(char));
    printf("double is %lu byte\n", sizeof(double));
    printf("float is %lu byte\n", sizeof(float));
    printf("int is %lu byte\n", sizeof(int));
    printf("long long is %lu byte\n", sizeof(long long));
    printf("string is %lu byte\n", sizeof(string));
    
    printf("\n");
    return 0;
}