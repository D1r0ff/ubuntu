#ifndef _K_H
#define _K_H
#include <stdbool.h>
#define SIZE 4

struct game {
    char board[SIZE][SIZE];
    int score;
};

void add_random_tile(struct game *game);                 //*

bool update(struct game *game, int dy, int dx);         //TODO A+A

bool is_move_possible(const struct game game);          //*

bool is_game_won(const struct game game);               //*

void print_board(struct game *game, int dy, int dx);    //*

void print_start(struct game *game);                    //*


#endif
