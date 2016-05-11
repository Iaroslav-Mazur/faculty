#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>


int main(){
    pid_t pid_fiu;

    struct flock lacat;
    struct flock delacat;
    lacat.l_type   = F_WRLCK;
    lacat.l_whence = SEEK_SET;
    lacat.l_start  = 0;
    lacat.l_len    = 1;

    delacat.l_type   = F_UNLCK;
    delacat.l_whence = SEEK_SET;
    delacat.l_start  = 0;
    delacat.l_len    = 1;

    int len_to_read = 0;

    int replici, fq = open("comunicare.txt", O_RDWR);
    char TIP;

    if(-1 == fq){
        perror("Nu am putut deschide fisierul de comunicare !\n");
        exit(1);
    }

    if(-1 == (pid_fiu=fork())){
        perror("Nu am putut face un proces nou !\n");
    }

    char val, reval;
    if(pid_fiu == 0){
        // fiu
        printf("Sunt in FIU cu pidul : %d \n", getpid());
        replici = open("fiu.txt", O_RDWR);
        TIP = 'F';
        len_to_read = 6;
        val = 'P';
        reval = 'F';
    }else{
        // parinte
        printf("Sunt in PARINTE cu pidul : %d \n", getpid());
        replici = open("parinte.txt", O_RDWR);
        TIP = 'P';
        len_to_read = 10;
        val = 'F';
        reval = 'P';
    }

    if(-1 == replici){
        perror("Nu am putut deschide fisierul cu replici !\n");
        exit(2);
    }

   int return_lock;
   int return_read;
   char line[len_to_read];
   while(return_read = read(replici, &line, sizeof(line))){
       char current_val = -1;

        if(return_read == -1){
            fprintf(stderr, "%c : Nu am putut citi \n!", TIP);
            exit(3);
        }
        /* printf("Compare %d ? %d \n", current_val, val); */

        while(current_val != val && current_val != 'D'){
            return_lock = fcntl(fq, F_SETLKW, &lacat);

            if(return_lock == -1){
                fprintf(stderr, "%c : Nu am putut pune lock pe conversatie !\n", TIP);
                exit(4);
            }
            lseek(fq, 0, SEEK_SET);
            int r = read(fq, &current_val, sizeof(current_val));

            return_lock = fcntl(fq, F_SETLK, &delacat);
            if(return_lock == -1){
                fprintf(stderr, "%c : Nu am putut scoate lock pe conversatie !\n", TIP);
                exit(4);
            }    

            /* printf(" ---XX-- %c : am gasit %c \n", TIP, current_val); */
        }


        return_lock = fcntl(fq, F_SETLKW, &lacat);
        if(return_lock == -1){
            fprintf(stderr, "%c : Nu am putut pune lock pe conversatie !\n", TIP);
            exit(4);
        }

        if(current_val != 'D'){
            
            lseek(fq, 0, SEEK_SET);
            if( sizeof(reval) > write(fq, &reval, sizeof(reval)) ){
                fprintf(stderr, "%c : Nu am putut scrie in conversatie !\n ", TIP);
                exit(5);
            }

        }

        return_lock = fcntl(fq, F_SETLK, &delacat);
        if(return_lock == -1){
            fprintf(stderr, "%c : Nu am putut scoate lock pe conversatie !\n", TIP);
            exit(4);
        }    


        fprintf(stdout, "%s", line);

        /* printf(" NOI AM CITIT %c : am gasit %c \n", TIP, current_val); */
   }

    char end='D';
    return_lock = fcntl(fq, F_SETLKW, &lacat);
    if(return_lock == -1){
        fprintf(stderr, "%c : Nu am putut pune lock pe conversatie !\n", TIP);
        exit(4);
    }

    lseek(fq, 0, SEEK_SET);
    if( sizeof(reval) > write(fq, &end, sizeof(end)) ){
        fprintf(stderr, "%c : Nu am putut scrie in conversatie !\n ", TIP);
        exit(5);
    }

    return_lock = fcntl(fq, F_SETLK, &delacat);
    if(return_lock == -1){
        fprintf(stderr, "%c : Nu am putut scoate lock pe conversatie !\n", TIP);
        exit(4);
    }

    /* printf("Am terminat !"); */
    close(replici);
    close(fq);
    return 0;
}
