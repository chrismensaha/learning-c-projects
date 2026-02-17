/*
Program 1: The Binary "Save State"
Goal: Master fwrite, fread, and struct persistence.

Instead of writing text that you can read in Notepad,
you will save the literal bits of a C struct to a file.

The Idea: Create a "Player Profile" for a game.

The New Logic: * Define a struct containing a name (char array), a level (int), and health (float).

Use fwrite(&player, sizeof(player), 1, fp) to save it.

Create a separate "Load" function that uses fread to pull that data back into a blank struct.

Why: You'll notice the resulting file is unreadable in a text editor,
but it's incredibly fast to load/save because no "parsing" of text is required.
 */
#include <stdio.h>
#include <string.h>
#define BUFFER 100

typedef struct player{
    char name[50];
    unsigned int level;
    float health;
    float experience;
} Player;

int main(){
    Player player;
    FILE* fileptr=("initial_file.txt","r");
    fwrite(&player,sizeof(player),1,fileptr);

    close(fileptr);
    return 0;
}