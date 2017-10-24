#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<termios.h>
#include<unistd.h>
    struct termios term;
    struct termios save;
/*Plese Term first*/
void Term(void){
    tcgetattr(STDIN_FILENO, &term);
    save = term;
    term.c_lflag &= ~ICANON;
    term.c_lflag &= ~ECHO;
}
int Slct(){
    int a,b,c,sw=1;
    int tmp='A';
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fprintf(stderr,"\033[5h");
    fprintf(stderr,"\033[2K");
    while(tmp!=10){
        if(tmp=='B'){
            sw++;
            if(sw==3){
                sw=0;}
        }else if(tmp=='A'){
            sw--;
            if(sw==-1){
                sw=2;}
        }
        switch(sw){
            case 0:a=007;b=000;c=000;break;
            case 1:a=000;b=007;c=000;break;
            case 2:a=000;b=000;c=007;break;
        }
        fprintf(stderr,"\033[2K");
        fprintf(stderr, "\r\033[0K\033[%dm A:Login \n\033[0m \033[%dmB:Bye \n\033[0m \033[%dmC:Game \n\033[0m\033[0K ",a,b,c);
        tmp = fgetc(stdin);
        fprintf(stderr,"\033[%dA",3);
    }
    fprintf(stderr,"\033[J");
    fprintf(stderr,"\033[%dD",3);
    tcsetattr(STDIN_FILENO, TCSANOW, &save);
    return sw;
}
int main(void){
    Term();
    Slct();
}
