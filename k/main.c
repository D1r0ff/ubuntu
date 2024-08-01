#include "k.h"
#include "hof.h"

int main(int argc, char* argv[]){
    srand(time(NULL));
    struct game game = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            },
        .score = 0
    };

    struct player list[10];

    // printf("Enter your name\n");
    // char name[30];
    // fgets(name, 30, stdin);
    // for(int i=0; i<strlen(name); i++){
    //     if(name[i]=='\n'){
    //         name[i]='\0';
    //     }
    // }

    struct player player;
    //strcpy(player.name, name);
    strcpy(player.name, argv[1]);
    
    add_random_tile(&game);
    add_random_tile(&game);
    add_random_tile(&game);

    print_start(&game);

    int move=0;
    int dy=0;
    int dx=0;
    int size=load(list);
    save(list, size);
    
    while(is_game_won(game)!=true){                              

        if(is_move_possible(game)!=true){
            printf("\nYou can not do next move\n\n");
            break;
        }

        printf("Your move?\n\n1-LEFT\n2-RIGHT\n3-UP\n4-DOWN\n5-read hall of fame\n6-end game\n");
        scanf("%i", &move);
        if(move==1){
            dy=0;
            dx=-1;
        }
        if(move==2){
            dy=0;
            dx=1;
        }
        if(move==3){
            dy=-1;
            dx=0;
        }  
        if(move==4){
            dy=1;
            dx=0;
        }
        if(move==5){
            print_list(list, size); 
            continue;                                            
        }
        if(move==6){
            break;
        }

        update(&game, dy, dx);
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                if(game.board[i][j]==' '){
                    add_random_tile(&game);
                    j=SIZE;
                    i=SIZE;
                }
            }
        }
        print_board(&game, dy, dx);

        if(is_game_won(game)==true){
            printf("\n   YOU ARE WON !!!!!\n");
            break;
        }
       
    }

    player.score=game.score;
    //player.score=10;
    if(add_player(list, &size, player)==true){
        save(list, size);
    }
    print_list(list, size);
    return 0;
}