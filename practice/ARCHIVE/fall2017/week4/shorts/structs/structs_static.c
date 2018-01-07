#include <stdio.h>
#include <cs50.h>

//STRUCTS: new data type
typedef struct{
    char* name;
    int lvl;
    int health;
} player;

int main(){

    player test;

    test.name = "Player 1";
    test.lvl = 1;
    test.health = 100;

    //debug output
    printf("Player Name: %s \n", test.name);
    printf("Player Level: %i \n", test.lvl);
    printf("Player Health: %i \n", test.health);

    printf("\n");   //new line
    return 0;
}

