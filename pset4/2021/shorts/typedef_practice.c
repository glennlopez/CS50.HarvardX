#include <stdio.h>
#include <cs50.h>

// char* to string
typedef char* string;

// health struct
typedef struct health
{
    bool is_alive;
    int qty;
}
health;

typedef struct coord
{
    int x;
    int y;
}
sprite_coord;

// player struct
typedef struct player
{
    health health;
    sprite_coord coord;
    string name;
    int score;
} player;

// prototype
void init_player(player[]);
void set_playerName(player p[]);

// global vars
int player_count;



int main()
{

    // create player structs
    player_count = get_int("How many players: ");
    printf("\n");
    player p[player_count];

    // initialize player
    init_player(p);
    set_playerName(p);]
    printf("\n");




    // debug show player info
    for (int i = 0; i < player_count; i++)
    {
        printf("Health: %i\n", p[i].health.qty);
        printf("Coord: %ix, %iy\n", p[i].coord.x, p[i].coord.y);
        printf("Name: %s\n", p[i].name);
        printf("Score: %i\n", p[i].score);
        printf("\n"); // new line
    }


}


void set_playerName(player p[])
{
    for (int i = 0; i < player_count; i++)
    {
        // name the player
        char* name = get_string("Player name: ");
        p[i].name = name;
    }
}


// init player stats
void init_player(player p[])
{
    for (int i = 0; i < player_count; i++)
    {
         p[i].health.qty = 100;
         p[i].coord.x = 0;
         p[i].coord.y = 0;
         p[i].name = "Player";
         p[i].score = 0;
    }
}