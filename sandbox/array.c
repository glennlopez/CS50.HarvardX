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
void draw(void);
bool move(int tile);


//MAIN ROUTINE
int main(){
    int usrNum;
    
    d = 5;          //<-- user input for board size
    usrNum = 1;     //<-- user input for number to swap
    init();         //<-- init subroutine
    draw();         //<-- draw the board
    move(usrNum);
    draw();         //<-- draw the board
    return 0;
}

















//MOVE SUBROUTINE
 /* If tile borders empty space, moves tile and returns true, else
 * returns false.  
 */
bool move(int tile){ 
    
     //START MOVE ROUTINE
    bool tile_exists = false; 
    bool tile_movable = false;
    
    //index user tile and blank tile
    int x = 0; int y = 0;   //user tile index 
    int a = 0; int b = 0;   //blank tile index
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            
            //search for user tile
            if(board[i][j] == tile){
                x = i; y = j;
                tile_exists = true;
            }
            
            //search for blank tile
            if(board[i][j] == 0){
                a = i; b = j;
            }
        }
    }
    
    //check if tile exists
    if(tile_exists == false){
        return false;   // tile doesnt exist - invalid move
    }
   
    //Check inner tiles
    if( (y != 0) && (y != (d - 1) ) ){ 
        if( board[x][y + 1] == board[a][b]){    //y: rightside
            tile_movable = true;
        }
        if( board[x][y - 1] == board[a][b]){    //y: leftside
            tile_movable = true;
        }
    }
    if( (x != 0) && (x != (d - 1) ) ){ 
        //printf("Within x limits..\n");
        if( board[x + 1][y] == board[a][b]){    //x: below
            tile_movable = true;
        }
        if( board[x - 1][y] == board[a][b]){    //x: above
            tile_movable = true;
        }
    }
    
    //Check outer tiles
    if(y == 0){                                 
        if( board[x][y + 1] == board[a][b]){    //y: rightside at orgin
            tile_movable = true;
        }  
    }
    if(y == (d - 1)){                          
        if( board[x][y - 1] == board[a][b]){    //y: leftside at d-limit
            tile_movable = true;
        }  
    }
    if(x == 0){                                 
        if( board[x + 1][y] == board[a][b]){    //x: below at orgin
            tile_movable = true;
        }  
    }
    if(x == (d - 1)){                          
        if( board[x - 1][y] == board[a][b]){    //x: above at d-limit
            tile_movable = true;
        }  
    }

    //swap empty tile
    if(tile_movable == true){
        int buffer = board[x][y];
        board[x][y] = board[a][b];
        board[a][b] = buffer;
        return true;
    }

    return false;
    //END MOVE ROUTINE
    
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