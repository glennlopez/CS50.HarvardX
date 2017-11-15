#include <stdio.h>
#include <cs50.h> 

//object struct
typedef struct obj{
    char* objectName;
    int objectID;
} object;

//player struct
typedef struct player{
    char* playerName;
    int playerScore;
} player;

int main(){
    
    int MAX_SHELF = 3; 
    int MAX_PLAYER = 1;
    
    object shelf[MAX_SHELF];
    player player1[MAX_PLAYER];
    
    //object data
    shelf[0].objectName = "Book Shelf";     shelf[0].objectID = 001;
    shelf[1].objectName = "Plant Shelf";    shelf[1].objectID = 002;
    shelf[2].objectName = "Toy Shelf";      shelf[2].objectID = 003;
    
    //player data
    player1[0].playerName = "Glenn";         player1[0].playerScore = 100;
    
    
    
    for(int i = 0; i < MAX_SHELF; i++){
        printf("Shelf: %s (%i)\n", shelf[i].objectName, shelf[i].objectID);
    }
    
    for(int i = 0; i < MAX_PLAYER; i++){
        printf("Player (%s) Score: %i\n", player1[i].playerName, player1[i].playerScore);
    }
    
    
    return 0;
}