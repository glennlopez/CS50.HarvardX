#include <stdio.h>
#include <cs50.h>
#include <string.h>

//STRUCTS: new data type
typedef struct{
    char* name;
    int lvl;
    int health;
} player;

//prototypes
void player_defaults(player *param);
void print_stats(player *param);
void set_name(player *param, char *);
void set_lvl(player *param, int);
void set_health(player *param, int);
void add_lvl(player *param, int);
void remove_health(player *param, int);
void add_health(player *param, int);

int main(){

    // INITIALIZE VARIABLES
    player *npc_001 = malloc( sizeof(player) ); //<-- allocates npc to HEAP memory 
    player *npc_002 = malloc( sizeof(player) ); //<-- allocates npc to HEAP memory
    
    //INITIALIZE NPC's
    player_defaults(npc_001);
    player_defaults(npc_002);

    //MODIFY STATS
    set_name(npc_001, "Barney");
    add_lvl(npc_001, 10);
    remove_health(npc_001, 12);

    set_name(npc_002, "Bob");
    
    //PRINT OUT PLAYER STATS
    print_stats(npc_001);
    print_stats(npc_002);

    //MEMORY CLEANUP
    free(npc_001);
    free(npc_002);

    printf("\n");   //new line
    return 0;
}



//subroutine for setting up default stats
void player_defaults(player *param){
    param->name = "???";
    (*param).lvl = 1;
    param->health = 100;
}

//subroutine for printing out player stats
void print_stats(player *param){
    printf( "Object Name: %s\n", param->name );
    printf( "Level: %i\n", param->lvl );
    printf( "Health: %i\n", param->health );
    printf("\n");
}

//subroutines for modifying data
void set_name(player *param, char *newName){
    param->name = newName;
}
void set_health(player *param, int newHealth){
    param->health = newHealth;
}
void set_lvl(player *param, int newLVL){
    param->lvl = newLVL;
}
void add_lvl(player *param, int lvlMod){
    param->lvl += lvlMod;
}
void add_health(player *param, int healthMod){
    param->health += healthMod;
}
void remove_health(player *param, int healthMod){
    param->health -= healthMod;
}
