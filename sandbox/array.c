#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];
int d;
int usrNum;


// prototypes
void init(void);
void draw(void);
bool move(int tile);


//MAIN ROUTINE
int main(){
    
    d = 3;  //<-- user input
    usrNum = 4;
    init(); //<-- init subroutine
    draw(); //<-- draw the board
    move(usrNum);
    return 0;
}







//MOVE SUBROUTINE
 /* If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile){
    /* TODO:
        * given the tile number (not location)
            [] find the tile location as per user input
    */
    
    //find tile number as per user
    printf("UserNum: %i\n", tile);
    printf("UserNum Location: %i\n", tile);
    return tile;
}















//DRAW SUBROUTINE
 /* Prints the board in its current state.
 */
void draw(void){
    //START DRAW ROUTINE
    //print array
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            if(board[i][j] == 0){
                printf(" _ ");
            }
            else{
                printf("%2i ", board[i][j]);  
            }
        }
        printf("\n");
    }printf("\n");
    //END DRAW ROUTINE
}


//INIT SUBROUTINE
/* Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void){
    //START INITIALIZE BOARD ROUTINE
    //add values to tiles
    int tileValue = (d*d) -1;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
           board[i][j] = tileValue;
           tileValue--;
        }
    }  
    
    //odd tile swap
    if(((d*d)-1) % 2){
         board[d-1][d-2] = 2;
         board[d-1][d-3] = 1;
    }
    //END INITIALIZE BOARD ROUTINE
}