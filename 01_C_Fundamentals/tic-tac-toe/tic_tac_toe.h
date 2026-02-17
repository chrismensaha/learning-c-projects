#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#define SIZE 3
 

char display_board(char board[SIZE][SIZE]);

int check_move( char board[SIZE][SIZE], int row,  int col, int size );

void make_move( char *target, char symbol);

void run_game(char board[SIZE][SIZE]);

#endif
