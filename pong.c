//I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>
int checkState(int x , int y,int player_1,int player_2, int ball_pos_x, int ball_pos_y) {
    if(x==1&&(y==player_1||y==player_1-1||y==player_1+1))
    {
        return 1;
    }
    else if(x==78&&(y==player_2||y==player_2-1||y==player_2+1))
    {
        return 1;
    }else if(x == ball_pos_x && y == ball_pos_y)
    {
        return 2;
    }
    return 0;
    
}
void table_score_1(int score_1,int score_2) {
    printf("|------------------------------------------------------------------------------|\n");
    printf("|                                      %d|%d                                     |\n",score_1,score_2);
}
void table_score_2(int score_1,int score_2) {
    printf("|------------------------------------------------------------------------------|\n");
    printf("|                                     %d|%d                                     |\n",score_1,score_2);
}
void table_score_3(int score_1,int score_2) {
    printf("|------------------------------------------------------------------------------|\n");
    printf("|                                      %d|%d                                    |\n",score_1,score_2);
}
void table_score_4(int score_1,int score_2) {
    printf("|------------------------------------------------------------------------------|\n");
    printf("|                                     %d|%d                                    |\n",score_1,score_2);
}
int risovka(int player_1,int player_2, int ball_pos_x, int ball_pos_y) {
    for(int y=0;y<25;y++)
    {
        for(int x = 0; x < 80; x++){
            if(x==0||x==79)
            {
                printf("|");
            }else if(y==0||y==24){
                printf("-");
            }else{
                switch (checkState(x,y,player_1,player_2,ball_pos_y,ball_pos_x)) {
                    case 0:
                        printf(" ");
                        break;
                    case 1:
                        printf("I");
                        break;
                    case 2:
                        printf("*");
                        break;
                    default:
                        break;
                    }
                }
            }
        printf("\n");
    }
    printf("\n");
    return 0;
}
int main() {
//START CONFIG
    char letter;
    int speed = 1;
    int player_1=5;
    int player_2=15;
    int score_1 = 0;
    int score_2 = 0;
    int ball_pos_x=40;
    int ball_pos_y=13;
    int delta_y = 1;
    int delta_x = 1;
//START CONFIG
    int a;
    char b;
    printf("Для начала игры нажмите 1\n");
    printf("Для выхода нажмите 2\n");
    if (scanf("%d%c", &a, &b) != 2 || b != '\n') {
        printf("n/a");
        return 0;
    }
    if (a == 1) {
        printf("Игра началась!\n");
        table_score_1(score_1,score_2);
        risovka(player_1,player_2,ball_pos_y,ball_pos_x);
        while(score_1 < 21 && score_2 < 21){
            printf("Следующий ход!\n");
            if (scanf("%c", &letter) == ' '){
                continue;
            }
            if(score_1 < 10 && score_2 <10){
                table_score_1(score_1,score_2);
                } else if(score_1 >= 10 && score_2<10){
                    table_score_2(score_1,score_2);
                    }else if(score_2 >= 10 && score_1 <10){
                        table_score_3(score_1,score_2);
                        }else if(score_1 >= 10 && score_2 >= 10){
                            table_score_4(score_1,score_2);
                        }
            if (player_1 >= 22){
                player_1 = player_1 + 0;
            } else if (letter == 'A'){
            player_1 = player_1 + speed;
            }
            if (player_1 <= 2) {
               player_1 = player_1 + 0;
            }else if (letter == 'Z'){
               player_1 = player_1 - speed;
            }
            if (player_2 >= 22){
                player_2 = player_2 + 0;
            } else if (letter == 'K'){
            player_2 = player_2 + speed;
            }
            if (player_2 <= 2) {
               player_2 = player_2 + 0;
            }else if (letter == 'M'){
               player_2 = player_2 - speed;
            }
      
            if ((ball_pos_x == 78 && player_2 == ball_pos_y) || (ball_pos_x == 78 && player_2+1 == ball_pos_y ) ||(ball_pos_x == 78 && player_2-1 == ball_pos_y )){
                delta_x *= -1;
            }  else if ((ball_pos_x == 1 && player_1 == ball_pos_y) || (ball_pos_x == 1 && player_1+1 == ball_pos_y ) ||(ball_pos_x == 1 && player_1-1 == ball_pos_y )){
                delta_x *= -1;
            } else if(ball_pos_x == 1){
                delta_x *= -1;
                score_2++;
            } else if (ball_pos_x == 78){
                delta_x *= -1;
                score_1++;
            }
            if (ball_pos_y == 1 || ball_pos_y == 23){
                delta_y*= -1;
            }
            if (delta_y == 1){
                ball_pos_y++;
            } else  if (delta_y == -1){
                ball_pos_y--;
            }
            if (delta_x == 1){
                ball_pos_x++;
            } else if(delta_x == -1)  {
                ball_pos_x--;
            }
            risovka(player_1,player_2,ball_pos_y,ball_pos_x);
        if(score_1 == 21){
            printf("Победил первый игрок!");
        } else if(score_2 == 21){
            printf("Победил второй игрок!");
        }
    }
    } else if (a == 2){
        printf("Выход!");
        return 0;
    } else {
        printf("n/a");
        return 0;
    }
    return 0;
}
