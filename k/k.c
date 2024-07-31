#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "k.h"

void add_random_tile(struct game *game){
    int row, col;
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while((*game).board[row][col] != ' ');
    
    if(rand() % 3 == 0){
        (*game).board[row][col] = 'B';
    }else{
        (*game).board[row][col] = 'A';
    }
}

bool is_game_won(const struct game game){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(game.board[i][j]=='K'){
                return true;
            }
        }
    }
    return false;
}

bool is_move_possible(const struct game game) {
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(game.board[i][j]==' '){
                return true;
            }
        }
    }
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-1; j++){
            if(game.board[i][j]==game.board[i][j+1] || game.board[i][j]==game.board[i+1][j]){
                return true;
            }
        }
    }
    return false;
}

bool update(struct game *game, int dy, int dx){
    if(is_move_possible(*game)==false){
        return false;
    }
    int index=0;
    bool lock=0;
    if(dy==0 && dx==1){                                                             //? move RIGHT
        for(int i=SIZE-1; i>=0; i--){
            for(int j=SIZE-1; j>=0; j--){
                if((*game).board[i][j]==' ' && lock!=true){
                    index=j;
                    lock=true;
                }
                if((*game).board[i][j]!=' ' && lock!=false){
                    (*game).board[i][index]=(*game).board[i][j];
                    (*game).board[i][j]=' ';
                    index--;
                }
            }
            index=0;
            lock =false;
        }
        for(int i=SIZE-1; i>=0; i--){
            for(int j=SIZE-1; j>0; j--){
                if((*game).board[i][j]==(*game).board[i][j-1] && (*game).board[i][j]!=' '){
                    (*game).board[i][j]++;
                    int count=(*game).board[i][j]-64;
                    printf("count: %i\n", count);
                    int points=1;
                    while(count!=0){
                        points=points*2;
                        count--;
                    }
                    (*game).score+=points;
                    (*game).board[i][j-1]=' ';
                    for(int p=j-1; p>0; p--){
                        (*game).board[i][p]=(*game).board[i][p-1];
                        (*game).board[i][p-1]=' ';
                    }
                }
            }
        }
    }
    

    if(dy==0 && dx==-1){                                                      //! move LEFT                      
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if((*game).board[i][j]==' ' && lock!=true){
                    index=j;
                    lock=true;
                }
                if((*game).board[i][j]!=' ' && lock!=false){
                    (*game).board[i][index]=(*game).board[i][j];
                    (*game).board[i][j]=' ';
                    index++;
                }
            }
            index=0;
            lock =false;
        }
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE-1; j++){
                if((*game).board[i][j]==(*game).board[i][j+1] && (*game).board[i][j]!=' '){
                    (*game).board[i][j]++;
                    int count=(*game).board[i][j]-64;
                    printf("count: %i\n", count);
                    int points=1;
                    while(count!=0){
                        points=points*2;
                        count--;
                    }
                    (*game).score+=points;
                    (*game).board[i][j+1]=' ';
                    for(int p=j+1; p<SIZE-1; p++){
                        (*game).board[i][p]=(*game).board[i][p+1];
                        (*game).board[i][p+1]=' ';
                    }
                }
            }
        }
    }

    if(dy==1 && dx==0){                                                             //* move DOWN
        for(int i=SIZE-1; i>=0; i--){
            for(int j=SIZE-1; j>=0; j--){
                if((*game).board[j][i]==' ' && lock!=true){
                    index=j;
                    lock=true;
                }
                if((*game).board[j][i]!=' ' && lock!=false){
                    (*game).board[index][i]=(*game).board[j][i];
                    (*game).board[j][i]=' ';
                    index--;
                }
            }
            index=0;
            lock =false;
        }
        for(int i=SIZE-1; i>=0; i--){
            for(int j=SIZE-1; j>0; j--){
                if((*game).board[j][i]==(*game).board[j-1][i] && (*game).board[j][i]!=' '){
                    (*game).board[j][i]++;
                    int count=(*game).board[j][i]-64;
                    printf("count: %i\n", count);
                    int points=1;
                    while(count!=0){
                        points=points*2;
                        count--;
                    }
                    (*game).score+=points;
                    (*game).board[j-1][i]=' ';
                    for(int p=j-1; p>0; p--){
                        (*game).board[p][i]=(*game).board[p-1][i];
                        (*game).board[p-1][i]=' ';
                    }
                }
            }
        }
    }

    if(dy==-1 && dx==0){                                                       //TODO move UP
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
               if((*game).board[j][i]==' ' && lock!=true){
                    index=j;
                    lock=true;
                }
                if((*game).board[j][i]!=' ' && lock!=false){
                    (*game).board[index][i]=(*game).board[j][i];
                    (*game).board[j][i]=' ';
                    index++;
                }  
            }
            index=0;
            lock =false;
        }
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE-1; j++){
                if((*game).board[j][i]==(*game).board[j+1][i] && (*game).board[j][i]!=' '){
                    (*game).board[j][i]++;
                    int count=(*game).board[j][i]-64;
                    printf("count: %i\n", count);
                    int points=1;
                    while(count!=0){
                        points=points*2;
                        count--;
                    }
                    (*game).score+=points;
                    (*game).board[j+1][i]=' ';
                    for(int p=j+1; p<SIZE-1; p++){
                        (*game).board[p][i]=(*game).board[p+1][i];
                        (*game).board[p+1][i]=' ';
                    }
                }
            }
        }
    }
    return false;
}


void print_board(struct game *game, int dy, int dx){
    if(dy==1 && dx==0){
        printf("\n     Move DOWN\n\n");
    }
    if(dy==0 && dx==1){
        printf("\n     Move RIGHT\n\n");
    }
    if(dy==0 && dx==-1){
        printf("\n     Move LEFT\n\n");
    }
    if(dy==-1 && dx==0){
        printf("\n     Move UP\n\n");
    }
    for(int i=0; i<SIZE; i++){
        printf(" %i | ", i+1);
        for(int j=0; j<SIZE; j++){
            printf("%c | ", (*game).board[i][j]);
        }
        printf("\n");
    }
    printf("    ");
    for(int i=0; i<SIZE; i++){
        printf("--- ");
    }
    printf("\n     ");
    for(int i=0; i<SIZE; i++){
        printf("%i   ", i+1);
    }
    printf("\n");
    printf("Current score: %i\n\n", (*game).score);
}

void print_start(struct game *game){
    printf("\n");
    for(int i=0; i<SIZE; i++){
        printf(" %i | ", i+1);
        for(int j=0; j<SIZE; j++){
            printf("%c | ", (*game).board[i][j]);
        }
        printf("\n");
    }
    printf("    ");
    for(int i=0; i<SIZE; i++){
        printf("--- ");
    }
    printf("\n     ");
    for(int i=0; i<SIZE; i++){
        printf("%i   ", i+1);
    }
    printf("\n");
}