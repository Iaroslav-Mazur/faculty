#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>


void citeste(int sig){
    char c;
    fseek(fd, SEEK_END, -1);
    char c;
    read(fd, &c, 1);
    if(c == 'a'){
        kill(pid_1, SIGUSR2);
    }
}

void sterge(int sig){
    /* char c; */
    /* fseek(fd, SEEK_END, -1); */
    /* char c; */
    /* read(fd, &c, 1); */
    /* if(c == 'a'){ */
    /*     kill(pid_1, SIGUSR2); */
    /* } */
}

int main(){
    pid_t pid_1;

    if((pid_1 = fork()) == -1){
        perror("P1: Eroare la deschiderea primului fisier.");
        exit(1);
    }


    // parinte
    if(pid_1){
        int fd = open("c.txt", O_APPEND);
        int i;
        if(fd == -1){
            perror("P1: Nu am putut deschide fisierul.");
            exit(2);
        }
        char s = 'a';
        while(s != 'x'){
            scanf("%c", &s);
            write(fd, &s, 1);
            printf("P1: Write %c \n", s);
            kill(pid_1, SIGUSR1);
        }
        printf("P1: Done\n");

    }else{
        // fiu 1
        int fd = open("c.txt", O_APPEND);
        int i;
        if(fd == -1){
            perror("P1: Nu am putut deschide fisierul.");
            exit(2);
        }

    }

}
