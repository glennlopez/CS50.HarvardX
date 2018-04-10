/* TODO:
    [x] Prompt and validate user input
        [x] Check for positive number
    [x] Calculate equivalent bottles
    [] Print equivalent bottles
*/

#include<stdio.h>
#include<cs50.h>

int get_posInt(void);
int calc_bottles(int param);

int main(){
    
    printf("Minutes: ");
    int usrNum = get_posInt();
    
    //print eq. bottles
    printf("Bottles: %i\n", calc_bottles(usrNum));  
    
    return 0;
}

//check get_int() for positive number
int get_posInt(void){int posInt = -9; //<-- declared outside the do-while loop (for scope)
    do{
        posInt = get_int();
    }while(posInt < 0);
    
    return posInt;
}

//calculate bottles
int calc_bottles(int param){
    return param * 12;
}