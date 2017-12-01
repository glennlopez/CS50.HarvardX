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
    player *npc_001 = malloc( sizeof(player) ); //<-- allocates npc to HEAP memory 
    
    //INITIALIZE NPC's
    player_defaults(npc_001);
    (*npc_001).name = "Barney";
    (*npc_001).lvl = 30;
    (*npc_001).health = 9001;

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
