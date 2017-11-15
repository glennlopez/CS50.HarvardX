#include<stdio.h>
#include<cs50.h>


int main(){

    //loop back when uNum is out of bounds
    int uNum = -99;
    while( (uNum < 0) || (uNum > 23) ){
        printf("Height: ");
        uNum = get_int();
    }


    for(int i = 1; i <= uNum; i++){

        //inserts spaces
        for(int j = uNum; j > i; j--){
            printf(" ");
        }

        //inserts hash
        for(int j = 0; j <= i; j++){
            printf("#");
        }

        //inserts new line
        printf("\n");
    }


    return 0;
}