#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    char *dir;

    if(argc >= 2){
        dir = argv[1];
    }else{
        int size = 128;
        char *buf = malloc(size);

        if(! buf){
            perror("[EROARE] Nu am putut aloca memerie pentru bufferul care va stoca CWD \n");
            return 1;
        }

        while(NULL == getcwd(buf, size)){
            size = size * 2;
            free(buf);
            buf = malloc(size);

            if(! buf){
                perror("[EROARE] Nu am putut aloca memerie pentru bufferul care va stoca CWD \n");
                return 1;
            }
        }

        dir = buf;
    }

    int pid = fork();
    if(-1 == pid){
        perror("[EROARE] Nu am putut crea fiul !");
        return 2;
    }
    
    if(! pid){
        execlp("ls", "ls", "-i", "-l", dir, NULL);

        perror("[EROARE] Nu am putut apela primitiva exec !");
        return 4;
    }

    int status;
    waitpid(pid, &status, 0);

    if(WIFEXITED(status)){
        printf("Comanda a fost executata cu succes !\n");
    }else{
        printf("Comanda nu a putut fi executata ...\n");
    }

    return 0;
}
