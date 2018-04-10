#include<stdio.h>
#include<cs50.h>

int get_posInt(void);
void printPyramid(int param);

int main(){
    
    int usrNum = get_posInt();
    printPyramid(usrNum);
    
    return 0;
}


//check get_int() for positive number
int get_posInt(void){int posInt = -9; 
    do{
        printf("Height: ");
        posInt = get_int();
    }while( (posInt < 0) || (posInt >= 24) );
    
    return posInt;
}


//print out pyramid
void printPyramid(int param){
    for(int i = 0; i < param; i++){
        for(int j = param; j > i+1; j--){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            printf("#");
        }
        printf("  ");
        for(int j = 0; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
}
