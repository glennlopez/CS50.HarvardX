#include <stdio.h>
#include <cs50.h>

//STRUCTS: new data type
typedef struct{
    char* name;
    int lvl;
    int health;
} player;

//prototypes
void player_defaults(player *param);

int main(){

    // INITIALIZE VARIABLES
    //player *player_1;                           //<-- allocates player to STACK memory
    //player player_2;                            //<-- allocated player to STACK memory
    player *npc_001 = malloc( sizeof(player) ); //<-- allocates npc to HEAP memory 
    //player *npc_002 = malloc( sizeof(player) ); //<-- allocates another npc to HEAP memory
    
    //INITIALIZE NPC's
    //player_defaults(struct player *npc_001);
    (*npc_001).name = "Barney";

    //DEBUG
    printf( "Object Name: %s\n", (*npc_001).name );
    printf( "Level: %i\n", (*npc_001).lvl);
    printf( "Health: %i\n", (*npc_001).health );

    //MEMORY CLEANUP
    free(npc_001);

    printf("\n");   //new line
    return 0;
}


void player_defaults(player *param){
    (*param).name = "???";
    (*param).lvl = 1;
    (*param).health = 100;
}
