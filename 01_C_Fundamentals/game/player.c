#define BUFFER 100
#include "game.h"



void create_player(){
    char creation_choice;
    printf("[1] to Create Your Own Player | [2] for Default: ");
    scanf("%c",&creation_choice);

    if (creation_choice!='1'){
        char name[6]="Player";
        for (int i=0;i<strlen(name);i++)
            player.name[i]=name[i];
        player.level=1;
        player.health=100.0; 
        player.experience=0.0;
        return;  
    }
    else{
        printf("Enter player name: ");
        fgets(player.name,BUFFER,stdin);
        player.name[strcspn(player.name,"\n")]=0;
    }
    printf("Enter player level: ");
    scanf("%ud",&player.level);
    while(getchar()!='\n');

    printf("Enter player health: ");
    scanf("%f",&player.health);
    while(getchar()!='\n');

    player.alive=1;
}

void gain_exp(float experience){
    player.experience+=experience;
}

void level_up(){ 
    while (player.experience>=100.0){
        player.level++;
        player.experience-=100;
    }
}

void player_take_dmg(float damage){ 
    if (player.health!=0){
        player.health-=damage;
    }
}

int player_is_dead(){ 
    char is_dead=0;
    if (player.health<=0){
        player.alive=0;
        is_dead=1;
        return is_dead;
    }
}

