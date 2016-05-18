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
    printf("Argv %d \n", argc);

    if(argc <= 1){
        char aux[100];
        printf("Care este directorul :");
        scanf("%s", aux);
        dir = aux;
    }else{
        dir = argv[1];
    }
    printf("Path este :%s \n", dir);

    int pid;
    pid = fork();

    if(! pid){
        // fiu de afisare
        execlp("ls", "ls", "-l", dir, NULL);
    }

    int status;
    char ch;
    waitpid(pid, &status, 0);

    printf("Doriti sa stergem directorul ? y / [N] ");
    scanf("%c", &ch);

    if(ch == 'y' || ch == 'Y'){
        pid = fork();

        if(! pid){
            char* argv[4];
            argv[0] = "/bin/rm";
            argv[1] = "-r";
            argv[2] = dir;
            argv[3] = NULL;
            execv(argv[0], argv);
        }
    }


    printf("Done \n");
    
    return 0;
}
