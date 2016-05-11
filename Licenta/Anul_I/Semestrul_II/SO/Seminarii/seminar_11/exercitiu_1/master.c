#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(){

    int pid;
    char semn[10], a[10], b[10], ex[2];
    ex[0] = 'x';
    ex[1] = '\0';
    /* char a, b, semn; */
    /* printf("Primul numar :"); */
    /* scanf("%s", a); */
    /* printf("Al doilea numar :"); */
    /* scanf("%s", b); */
    /* printf("Semnul  :"); */
    /* scanf("%s", semn); */



    /* while((char)*semn != 'x'){ */
    while(strcmp(semn, ex) != 0){
        printf("Primul numar :");
        scanf("%s", a);
        printf("Al doilea numar :");
        scanf("%s", b);
        printf("Semnul  :");
        scanf("%s", semn);

        if(-1 == (pid=fork())){
            perror("Nu am putut face un fiu !");
            exit(1);
        }

        if(pid == 0){
            // fiu
            printf("Suntem in fiu ! \n");
            char *path = "/home/mmicu/faculty/Licenta/Anul_I/Semestrul_II/SO/Seminarii/seminar_11/exercitiu_1/slave",
                *argv[5];
            argv[0] = path;
            argv[1] = a;
            argv[2] = b;
            argv[3] = semn;
            argv[4] = 0;

            execv(path, argv);
            /* execl(path, path, a, b, semn, '\0'); */
        }else{
            // parinte
            printf("Suntem in parinte ! \n");
            int rezultat = -1;
            waitpid(pid, &rezultat, 0);
            /* wait(rezultat); */
            printf("[ PARINTE ]Rezultatul este :%d \n", WEXITSTATUS(rezultat));
        }

    }


    return 0;
}
