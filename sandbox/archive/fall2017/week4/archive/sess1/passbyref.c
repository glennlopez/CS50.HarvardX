#include <stdio.h>
#include <cs50.h>

void passByRef(int *param_a, int *param_b){

    int temp = *param_a;
    *param_a = *param_b;
    *param_b = temp;
    
    printf("passByRef\n");
    printf("a(): %i\n", *param_a);
    printf("b(): %i\n", *param_b);

}

void passByVal(int param_a, int param_b){

    int temp = param_a;
    param_a = param_b;
    param_b = temp;

    printf("passByVal\n");
    printf("a(): %i\n", param_a);
    printf("b(): %i\n", param_b);

}

int main(){
    
    int a = 5;
    int b = 10;
    

    //print values before
    printf("a: %i\n", a);
    printf("b: %i\n", b);

    passByRef(&a,&b);
    //passByVal(a,b);
    
    //print values after
    printf("a: %i\n", a);
    printf("b: %i\n", b);
    
    return 0;
}
