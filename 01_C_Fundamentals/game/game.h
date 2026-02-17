#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string.h>

typedef struct player{
    char name[50];
    unsigned int level;
    char alive;
    float health;
    float experience;   
} Player;
Player player;
typedef struct enemy{
    char name[50];
    char type[10];
    char alive;
    unsigned int level;
    float health;
} Enemy;
Enemy enemy;
void player_take_dmg(float damage);
void gain_exp(float experience);
int player_is_dead();
void create_player();
void level_up();




#endif