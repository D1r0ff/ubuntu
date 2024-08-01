#include "k.h"

#ifndef _HOF_H
#define _HOF_H

#include <stdbool.h>

#define HOF_FILE "score"
#define DELIMITER " "

struct player{
    char name[30];
    int score;
};


int load(struct player list[]);      


bool save(const struct player list[], const int size);    


void print_list(struct player list[], const int size);


bool add_player(struct player list[], int* size, const struct player player);            

#endif