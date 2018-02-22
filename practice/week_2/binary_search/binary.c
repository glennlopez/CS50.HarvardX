#include <stdio.h>
#include <cs50.h>

void binarySearch(int []);

int main(){

    int ar[] = {0,2,4,6,7,8,13,23,43,55};
    binarySearch(ar);



    //outputs
    for(int i = 0; i < 10; i++){
        printf("%i ", *(ar + i));
    }

    printf("\n");
    return 0; 
}




/* SUBROUTINE */
void binarySearch(int param[]){
    //get usr input
    int usrNum = get_int("Search: ");

    
    //debug
    printf("usrNum: %i\n", usrNum);
}
