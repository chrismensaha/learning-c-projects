#include "game.h"

Enemy enemy;

void enemy_take_dmg(float damage){
    if (enemy.health!=0){
        enemy.health-=damage;
    }
}

int enemy_is_dead(){   
    char is_dead=0;
    if (enemy.health<=0){
        enemy.alive=0;
        is_dead=1;   
        return is_dead;
    }
}

