#include "tic_tac_toe.h"
#include <stdio.h>
#include <stdlib.h>


void display_board(char board[SIZE][SIZE]){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            printf("%c",board[i][j]);
            if (j<SIZE-1){
                printf("|");
            }
        }
        printf("\n");
        if (i<SIZE-1){
            printf("---+---+---");
        }               
    }
}

void make_move( char *target, char symbol){
    *target = symbol;
}

int check_move( char board[SIZE][SIZE], int row,  int col, int size ){
    if (row<0 || row<=SIZE || col<0 || col<=size) 
        return 0;
    if (board[row][col]==' ')
        return 1; 
    else
        return 0;       
}

void init_game(char board[SIZE][SIZE]){
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            board[i][j]=' ';
        }
    }
}

void run_game(char board[SIZE][SIZE]){   
    char player=' ';
    int row=0, col=0;
    int turn=0;
    init_game(board);
    
    while(1){
        printf("Choose your player (X) OR (O):");
        scanf(" %c",&player);
        if (player=='O' || player=='X'){
            printf("Invalid Input! Try Again");
        }
    }

    while(1){
        display_board(board);
        printf("Select Your Space (Row,Column): ");
        if (scanf("%d,%d",&row,&col)!=2){
            printf("Error! Try another space");
            continue;
        }

        if (check_move(board,row,col,SIZE)==1){
            make_move(&board[row][col],player);
            
            break;
        }     
                         
    }         
}
