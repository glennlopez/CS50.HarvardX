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
    
    d = 9;      //<-- user input for board size
    usrNum = 0; //<-- user input for number to swap
    init();     //<-- init subroutine
    draw();     //<-- draw the board
    move(usrNum);
    return 0;
}







//MOVE SUBROUTINE
 /* If tile borders empty space, moves tile and returns true, else
 * returns false.  
 */
bool move(int tile){
    
    //index the location of the array userNum is in
    int x = 0; int y = 0; 
    while(x < d){
        
        //do not loop if userNum is too large or too small
        if( (usrNum > ((d*d) - 1)) || (usrNum < 0)){
            break;
        }
            
        y = 0;
        while(y < d){
            if(board[x][y] == usrNum){
                break;
            }
            y++;
        }
        
        if(board[x][y] == usrNum){
            break;
        }
        x++;
    }
    
    //debug printf
    printf("x: %i y: %i is %i\n", x, y, board[x][y]);   //new line
    printf("\n");   //new line
    printf("UserNum: %i\n", tile);
    
    
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