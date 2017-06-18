#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX];
int d;


// prototypes
void init(void);



//MAIN ROUTINE
int main(){
    
    d = 3;
    
    init();
    
    //print array
    for(int i = 0; i < d; i++){
        
        board[i] = i + 1;
        printf("%i ", board[i]);

    }printf("\n");
    
    return 0;
}





//INIT SUBROUTINE
/* Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void){
    
    printf("init() excecuted!\n");
    
}