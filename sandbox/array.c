#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];
int d;


// prototypes
void init(void);



//MAIN ROUTINE
int main(){
    
    d = 4;  //<-- user input
    init(); //<-- init subroutine
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //print array
    for(int i = 0; i < d; i++){
        
        for(int j = 0; j < d; j++){
            printf("%i ", board[i][j]);
        }printf("\n");

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