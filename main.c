//Date : 2015-3-21 19:34
//Author : 张宇阳(helloqiu || heheda)
//Description : write a game push case
//
//Date : 2015-3-21 23:00
//Author : 张宇阳(helloqiu || heheda)
//Description : change move() to make the code more clear
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define dx 8
#define dy 1

char map[10][10] = {'*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*',
                   '*' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , '*' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , '*' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , '*' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , '*' , ' ' , ' ' , ' ' , '*' , ' ' , '*',
                   '*' , ' ' , ' ' , '*' , ' ' , ' ' , ' ' , ' ' , ' ' , '*',
                   '*' , 'D' , ' ' , '*' , ' ' , ' ' , ' ' , ' ' , ' ' , '*',
                   '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*'};
int pnowx = 1;
int pnowy = 8;
int cnowx = 7;
int cnowy = 7;
void refresh(void);
int move(char to);
int win(void);
int main(void)
{
    char step;//the step that entered
    refresh();
    printf("please enter your step : ");
    while (!win()){
        step = _getch();
        if(!move(step)){
            printf("can't move !\n");
        }else{
            refresh();
            printf("please enter your step : ");
        }

    }
    printf("you win!\n");
    return 0;
}
//refresh the map
void refresh(void){
    system("cls");
    for (int i = 0 ; i < 10 ; i ++){
        for (int j = 0 ; j < 10 ; j ++){
            if ((i == pnowx) && (j == pnowy)){
                printf("# ");
            }else{
                if ((i == cnowx) && (j == cnowy)){
                    printf("@ ");
                }else{
                    printf("%c " , map[i][j]);
                }
            }
        }
        printf("\n");
    }
}
//move action
//return 0 : can't move
//return 1 : move successfully
int move(char to){
    int move_x = 0;
    int move_y = 0;
    switch (to){
        case 'w' :
            move_x = -1;
            break;
        case 's' :
            move_x = 1;
            break;
        case 'a' :
            move_y = -1;
            break;
        case 'd' :
            move_y = 1;
            break;
    }
    if ((pnowx + move_x == cnowx) && (pnowy + move_y == cnowy)){
        if (map[cnowx + move_x][cnowy + move_y] != '*'){
            cnowx += move_x;
            cnowy += move_y;
            pnowx += move_x;
            pnowy += move_y;
            return 1;
        }else{
            return 0;
        }
    }
    if (map[pnowx + move_x][pnowy + move_y] != '*'){
        pnowx += move_x;
        pnowy += move_y;
        return 1;
    }else{
        return 0;
    }
}
//judge if win
int win(void){
    if ((cnowx == dx) && (cnowy == dy)){
        return 1;
    }
    return 0;
}

