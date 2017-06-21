/**
 * fifteen.c 
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d 
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
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

/**
 * Prints the board in its current state.
 */
void draw(void)
{
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

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
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
    //START MOVE ROUTINE
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    return false;
}
