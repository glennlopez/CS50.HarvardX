#include <cs50.h>
#include <stdio.h>
#include <math.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(){
    int coins = 0;
    int cents = 0;
    float uNum = 0; //NOTE: if you change datatype from float to double see what happens

    //loop back when uNum is out of bounds
    do{
        printf("How much change is owed?\n");
        uNum = get_float();
    }
    while(uNum < 0);

    //converts $1.00 to 100 cents
    cents = round(uNum * 100);  //<-- round prevents float to int errors

    while(cents > 0){

        if(cents >= QUARTER){
            coins++;
            cents -= QUARTER;
        }

        else if(cents >= DIME){
            coins++;
            cents -= DIME;
        }

        else if(cents >= NICKEL){
            coins++;
            cents -= NICKEL;
        }

        else if(cents >= PENNY){
            coins++;
            cents -= PENNY;
        }

        else{
            coins++;
            cents -= QUARTER;
        }

        /*  //FAILS
        if( !(cents % QUARTER) ){
            coins++;
            cents -= QUARTER;
        }

        else if( !(cents % DIME) ){
            coins++;
            cents -= DIME;
        }

        else if( !(cents % NICKEL) ){
            coins++;
            cents -= NICKEL;
        }

        else if( !(cents % PENNY) ){
            coins++;
            cents -= PENNY;
        }
        */
    }



    printf("%i\n", coins);

    return 0;
}