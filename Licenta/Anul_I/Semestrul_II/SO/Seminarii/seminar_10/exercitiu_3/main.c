#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int n;
	if(argc < 2){
		fprintf(stderr, "Avem nevoie de macar un parametru de tip int !\n");
        return 1;
	}
    n = atoi(argv[1]);

    if(n < 0 ){
        fprintf(stderr, "N nu poate fi mai mic decat 0 [ am primid %d ]\n", n);
    }


    int pid, i;
	pid_t parinte = getpid();

    struct flock locking, unlocking;
    // blocare
    locking.l_type = F_WRLCK;
    locking.l_whence = SEEK_SET;
    locking.l_start = 0;
    locking.l_len = 1;

    // deblocare
    unlocking.l_type = F_UNLCK;
    unlocking.l_whence = SEEK_SET;
    unlocking.l_start = 0;
    unlocking.l_len = 1;

    for(i = 0; i < n; i++){
        pid = fork();

        if(pid == -1){
            fprintf(stderr, "Nu am putut crea fiul cu numarul %d \n", i);
        }

        if(pid){

			/* flock_s */
            if(-1 == fcntl(STDIN_FILENO, F_SETLKW, &locking)){
                perror("Nu am putut pune lacatul de scriere ! ");
                return 2;
            }

            printf("[FIU %d] Apel fiu cu parintele %d si pidul %d : !\n", i, parinte, getpid() );

            if(-1 == fcntl(STDIN_FILENO, F_SETLK, &unlocking)){
                perror("Nu am putut pune lacatul de scriere ! ");
                return 2;
            }

            return 0;
            // sunt in fiu !
        }
		// wait(NULL); solutie partiala ( generam doar un fiu o data )
    }

    wait(NULL);
    printf("[PARINTE] Am terminat !\n");

    return 0;
}
