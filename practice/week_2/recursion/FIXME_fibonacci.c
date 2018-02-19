#include <stdio.h>
#include <cs50.h>
int fibo(int);



int main(){

    /*
        0 + 1 = 1
        1 + 1 = 2
        1 + 2 = 3
        2 + 3 = 5
        3 + 5 = 8
        5 + 8 = 13

        a + b = c
        b + c = d
        c + d = e
        d + e = f
        
        a 
        b -> c
        c -> a

        [a][b][c]
        [1][2][?]   [a][b][c]
        [1][2][3]   [a][b][a+b](c)
        [2][3][?]   [b][c][b+c]
        [2][3][5]   

        a[2] = a[0] + a[1]
        x = a[2]
        y = a[1]
        a[0] = x
        a[1] = y



    */
    fibo(7);
    
    int a = 0;
    int b = 1;
    int c = 0;


    for(int i = 0; i < 12; i++){

        c = a + b;
        a = b;
        b = c;

        printf("%i ", a);

    }



    printf("\n");
    return 0;
}

int fibo(int n){
    //basecase
    if(1){

        return n;
    }

    //recursive case
    else{

    }
}