#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char argv[]){
    if(argc < 1){
        fprintf(stderr, "Avem nevoie de macar un parametru ! \n");
        exit(1);
    }

    int n = atoi(argv[i]);

    // first process
    int process = 1;
    int p1 = fork();
    if(-1 == p1 ){
        fprintf(stderr, "Nu am putut face forkul : %d \n", process);
        exit(1);
    }

    if(p1 == 0){
    // p1 main
    }else{
        // second process
        int process = 2;
        int p2 = fork();

        if(-1 == p2){
            fprintf(stderr, "Nu am putut face forkul : %d \n", process);
            exit(1);
        }

        if(p2 == 0){
            // p2 main
        }else{
            // main program 
            waitpid(p1);
            waitpid(p2);

        }
    }
        

    
    return 0;
}
