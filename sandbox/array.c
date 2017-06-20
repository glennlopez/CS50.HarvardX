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
    
    d = 3;      //<-- user input for board size
    usrNum = 6; //<-- user input for number to swap
    init();     //<-- init subroutine
    draw();     //<-- draw the board
    move(usrNum);
    return 0;
}







//MOVE SUBROUTINE
 /* If tile borders empty space, moves tile and returns true, else
 * returns false.  
 */
bool move(int tile){ bool tile_exists = false;
    
    //index user tile and blank tile
    int x = 0; int y = 0;   //user tile index 
    int a = 0; int b = 0;   //blank tile index
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            
            //search for user tile
            if(board[i][j] == usrNum){
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
    
    
    
    //debug printf
    printf("x: %i y: %i is %i\n", x, y, board[x][y]);   //new line
    printf("a: %i b: %i is %i\n", a, b, board[a][b]);   //new line
    printf("\n");   //new line
    printf("UserNum: %i\n", tile);

   
    //TODO: tile borders empty space
    //if(y == (d/2)){    //y = middle 
    if( (y >= 1) && (y < d) ){    //y = middle 
        printf("IS in the middle\n");
        if( board[x][y + 1] == board[a][b]){    //y-pos: check leftside
            printf("Near empty tile\n");
        }
        if( board[x][y - 1] == board[a][b]){    //y-pos: check rightside
            printf("Near empty tile\n");
        }
    }

        

    
    
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