//Date : 2015-3-21 19:34
//Author : 张宇阳(helloqiu || heheda)
//Description : write a game push case
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
    if (to == 'w'){
        if ((pnowx == cnowx + 1) && (pnowy == cnowy)){
            if(map[cnowx - 1][cnowy] != '*'){
                pnowx -= 1;
                cnowx -= 1;
                return 1;
            }else{
                return 0;
            }
        }else{
            if (map[pnowx - 1][pnowy] != '*'){
                pnowx -= 1;
                return 1;
            }else{
                return 0;
            }
        }
    }

    if (to == 's'){
        if ((pnowx == cnowx - 1) && (pnowy == cnowy)){
            if(map[cnowx + 1][cnowy] != '*'){
                pnowx += 1;
                cnowx += 1;
                return 1;
            }else{
                return 0;
            }
        }else{
            if (map[pnowx + 1][pnowy] != '*'){
                pnowx += 1;
                return 1;
            }else{
                return 0;
            }
        }
    }
    if (to == 'a'){
        if ((pnowx == cnowx) && (pnowy == cnowy + 1)){
            if(map[cnowx][cnowy - 1] != '*'){
                pnowy -= 1;
                cnowy -= 1;
                return 1;
            }else{
                return 0;
            }
        }else{
            if (map[pnowx][pnowy - 1] != '*'){
                pnowy -= 1;
                return 1;
            }else{
                return 0;
            }
        }
    }
    if (to == 'd'){
        if ((pnowx == cnowx) && (pnowy == cnowy - 1)){
            if(map[cnowx][cnowy + 1] != '*'){
                pnowy += 1;
                cnowy += 1;
                return 1;
            }else{
                return 0;
            }
        }else{
            if (map[pnowx][pnowy + 1] != '*'){
                pnowy += 1;
                return 1;
            }else{
                return 0;
            }
        }
    }
}
//judge if win
int win(void){
    if ((cnowx == dx) && (cnowy == dy)){
        return 1;
    }
    return 0;
}

