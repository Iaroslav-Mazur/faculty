#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int pid;
    printf("[PARINTE] Incepem \n");

    if( -1 == (pid = fork()) ){
        perror("Nu am putut face un copil !");
        return 1;
    }

    if(!pid){
        // fiu
        execl("/usr/bin/cut", "/usr/bin/cut", "-d:", "-f1,3", "/etc/passwd", NULL);

        perror("[FIU] Nu am putut executa comanda EXEC\n");
        return 155;
    }

    // parinte
    int status;
    waitpid(pid, &status, 0 );
    printf("[PARINTE] Status : %d \n", WEXITSTATUS(status));

    if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
        printf("[PARINTE] Comanda a fost executat cu succes !\n");
    }else{
        printf("[PARINTE] Comanda NU a fost executat cu succes !\n");
    }

    return 0;
}
