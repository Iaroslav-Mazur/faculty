#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 4){
        fprintf(stdout, "Avem nevoie de min 3 argumente ( %d primite )\n", argc-1);
        return 1;
    }

    // parsam argumentele
    char c1 = argv[1][0],
         c2 = argv[2][0],
         c3 = argv[3][0];

    int pid,
        pipe_parinte_fiu1[2],
        pipe_fiu2_parinte[2];

    if(-1 == pipe(pipe_fiu2_parinte)){
        perror("Nu am putu crea pipe-ul fiu2 - parinte \n");
        return 3;
    }

    if(-1 == pipe(pipe_parinte_fiu1)){
        perror("Nu am putu crea pipe-ul parinte - fiu1 \n");
        return 3;
    }


    if(-1 == (pid = fork()) ){
        perror("Nu am putut crea primul copil \n");
        return 2;
    }

    if(!pid){
        printf("[FIU 1] Start \n");
        close(pipe_fiu2_parinte[0]);
        close(pipe_parinte_fiu1[1]);

        int pipe_fiu1_fiu2[2];
        if(-1 == pipe(pipe_fiu1_fiu2)){
            perror("Nu am putut crea al doilea pile !\n");
            return 3;
        }

        if(-1 == (pid = fork())){
            perror("Nu am putut crea al doiela fiu !\n");
            return 5;
        }

        if(!pid){
            // al doilea fiu
            close(pipe_fiu1_fiu2[1]);
            


            int inlocuiri = 0;
            char ch;
            while(read(pipe_fiu1_fiu2[0], &ch, sizeof(ch)) != 0){
                printf("[FIU 2] Am primit (%c) \n", ch);
                

                if(ch == c2){
                    printf("[FIU 2] ---  INLOCUIRE(%c -> %c) \n", ch, c3);
                    ch = c3;
                    inlocuiri++;
                }

                printf("[FIU 2] Dam mai departe (%c) \n", ch);
                write(pipe_fiu2_parinte[1], &ch, sizeof(ch));
            }
            printf("[FIU 2] Am facut %d inlocuiri \n", inlocuiri);

            return 0;
        }

        close(pipe_fiu1_fiu2[0]);

        int inlocuiri = 0;
        char ch;
        while(read(pipe_parinte_fiu1[0], &ch, sizeof(ch)) != 0){
            printf("[FIU 1] Am primit (%c) \n", ch);
            

            if(ch == c1){
                printf("[FIU 1] ---  INLOCUIRE(%c -> %c) \n", ch, c2);
                ch = c2;
                inlocuiri++;
            }

            printf("[FIU 1] Dam mai departe (%c) \n", ch);
            write(pipe_fiu1_fiu2[1], &ch, sizeof(ch));
        }
        printf("[FIU 1] Am facut %d inlocuiri \n", inlocuiri);
        close(pipe_parinte_fiu1[0]);
        close(pipe_fiu1_fiu2[1]);

        return 0;
    }

    printf("[PARINTE] Start \n");
    close(pipe_fiu2_parinte[1]);
    close(pipe_parinte_fiu1[0]);

    char ch[3];
    scanf("%s", ch);
    int i;
    for( i = 0; i < 3; i++){
        printf("[PARINTE] Trimitem (%c) \n", ch[i]);
        write(pipe_parinte_fiu1[1], &ch[i], 1);
    }
    close(pipe_parinte_fiu1[1]);

    
    char c;
    i = 0;
    while(read(pipe_fiu2_parinte[0], &c, sizeof(c)) != 0){
        printf("[PARINTE] Am primit (%c) \n", c);
        ch[i++] = c;
    }
    close(pipe_fiu2_parinte[0]);
    printf("[ - PARINTE - ] Final : %s \n", ch);


    return 0;
}
