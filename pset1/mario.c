#include<stdio.h>
#include<cs50.h>

int get_posInt(void);

int main(){
    
    unsigned int usrNum = get_posInt();
    printf("Num: %i\n", usrNum);    //print debug
    
    return 0;
}


//check get_int() for positive number
int get_posInt(void){int posInt = -999999; 
    do{
        posInt = get_int();
    }while( (posInt < 0) || (posInt >= 24) );
    
    return posInt;
}
