#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "hof.h"

int load(struct player list[])
{
    FILE *score = fopen("hof.txt", "r");
    if (score == NULL){
        printf("Can not find file\n");
        return -1;
    }

    char copy[10][30];
    int count = 0;

    for (int i=0; fgets(copy[i], 30, score) != NULL; i++){                   //! hof.txt -> copy
        count = i + 1;
        if(count==10){
            break;
        }
    }
    fclose(score);

    char c;
    int j;
    char points[count][30];

    for (int i = 0; i < count; i++){                                     //! copy -> list.name + points
        j = 0;
        list[i].score = 0;
        while ((c = copy[i][j]) != ' '){
            list[i].name[j] = c;
            j++;
        }
        int k = 0;
        while ((c = copy[i][j]) != '\n'){
            if ((c = copy[i][j]) == EOF){
                break;
            }
            points[i][k] = c;
            j++;
            k++;
        }
        points[i][k++] = '\0';
    }

    int ten = 1;
    for (int i = 0; i < count; i++){                                   //! points -> list.score
        for (int j = strlen(points[i]) - 1; j > 0; j--){
            list[i].score += (points[i][j] - 48) * ten;
            ten = ten * 10;
        }
        ten = 1;
    }

    int a = 10;
    char string[30];
    while (a != 0){
        for (int i = 0; i < count - 1; i++){                                  //! sort list
            if (list[i].score < list[i + 1].score){
                list[i].score += list[i + 1].score;
                list[i + 1].score = list[i].score - list[i + 1].score;
                list[i].score -= list[i + 1].score;
                strcpy(string, list[i].name);
                strcpy(list[i].name, list[i+1].name);
                strcpy(list[i+1].name, string);
            }
        }
        a--;
    }

    return count;
}

void print_list(struct player list[], const int size){
    printf("\nHall of fame:\n\n");
    for (int i = 0; i < size; i++){ 
        printf("Player %i name ", i+1);
        for(int j=0; j<strlen(list[i].name); j++){
            printf("%c", list[i].name[j]);
        }                                        
        printf(" score: %i\n", list[i].score);
    }
    printf("\n");
}

bool save(const struct player list[], const int size){
    FILE *score = fopen("hof.txt", "w");
    if (score == NULL){
        return false;
    }
    for(int i=0; i<size; i++){
        fprintf(score, "%s %i\n", list[i].name, list[i].score);
    }
    fclose(score);
    return true;
}

bool add_player(struct player list[], int* size, const struct player player){
    int index=0;

    for(int i=0; i<*size; i++){
       if(player.score>=list[i].score){
            index=i;
            break;
       } 
       if(i==*size-1){
            printf("You was not added to hall of fame!!!\n");
            return false;
       }
    }

    if(index==*size-1){
        list[index].score=player.score;
        strcpy(list[index].name, player.name);
        printf("You was added to hall of fame!!!\n");
        return true;
    }

    for(int j=*size-1; j>index; j--){
        list[j].score=list[j-1].score;
        strcpy(list[j].name, list[j-1].name);
        if(j==index+1){
            list[j-1].score=player.score;
            strcpy(list[j-1].name, player.name);
        }
    }
    printf("You was added to hall of fame!!!\n");
    return true;
}