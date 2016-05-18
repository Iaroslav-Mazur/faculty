#include <unistd.h> // pipe, fork
#include <fcntl.h> // pentru LOCK's
#include <errno.h> // pentru errno
#include <string.h> // pentru memset
#include <sys/types.h> // open
#include <sys/stat.h> // open
#include <sys/wait.h> // open
#include <stdio.h> // readline
#include <stdlib.h> //readline

#define MAX_SIZE 1024

int main(){
    int pid1, pid2, len;
    int pip_1_to_2[2], pip_2_to_1[2];


    printf("[PARINTE] Begin ! \n");

    char line[MAX_SIZE], ch;

    /* Cream pipeurile necesare */
    if( -1 == pipe(pip_1_to_2)){
        perror("[EROARE] Nu am putut crea pipe-ul de la fiu1 la fiu2  !\n");
        return 1;
    }

    if( -1 == pipe(pip_2_to_1)){
        perror("[EROARE] Nu am putut crea pipe-ul de la fiu2 la fiu1  !\n");
        return 1;
    }

    /* deschidem fisierul in care vor scriem ambele procese */
    int fout = open("persoane.txt", O_WRONLY|O_CREAT );
    FILE *file_out = fdopen(fout, "w");
    if( file_out == NULL || fout == -1 ){
            perror("[EROARE PARINTE]Nu am putut deschide fisierul persoane.txt !\n");
            return 3;
    }
    

    // ================================================================================
    // FIU 1
    pid1 = fork();
    if( -1 == pid1){
        perror("[EROARE] Nu am putut crea primul fiu ! \n");
        return 2;
    }

    if(! pid1){
        // primul fiu 
        close(pip_1_to_2[0]); // nu citim unde scriem
        close(pip_2_to_1[1]); // nu scriem unde citim

        // fisierul de citire 
        int fin = open("nume.txt", O_RDONLY);
        FILE *file =fdopen(fin, "r");
        if( file == NULL || fin == -1 ){
            perror("[EROARE FIU1]Nu am putut deschide fisierul nume.txt !\n");
            return 3;
        }

        while(fgets(line, sizeof(line), file)){
            // eliminam new-line
            int aux = 0;
            while(line[aux] != '\n'){
                aux++;
            }
            line[aux] = '\0';


            // asteptam sa ni se permita sa scriem
            read(pip_2_to_1[0], &ch, sizeof(ch));
            printf("[FIU1 ] Trebuie scris : %s \n ", line);

            /* write(fout, &line, strlen(line)); */
            fprintf(file_out,"%s ", line);
            fflush(file_out);

            // dam voie celuilalt proces sa scrie
            ch = 'o';
            write(pip_1_to_2[1], &ch, sizeof(ch));
        }

        if(!feof(file)){
            perror("[EROARE FIU1] Nu am ajuns la finaul fisierului prenume.txt !\n");
            return 5;
        }




        close(pip_1_to_2[1]);
        close(pip_2_to_1[0]);
        fclose(file);
        close(fin);

        fclose(file_out);
        close(fout);
        return 0;
    }


    // ================================================================================
    // FIU 2
    pid2 = fork();
    if( -1 == pid2){
        perror("[EROARE] Nu am putut crea al doilea fiu ! \n");
        return 2;
    }

    if(! pid2){
        // primul fiu 
        close(pip_1_to_2[1]); // nu scriem unde citim
        close(pip_2_to_1[0]); // nu citim unde scriem

        // fisierul de citire
        int fin = open("prenume.txt", O_RDONLY);
        FILE *file =fdopen(fin, "r");
        if( file == NULL || fin == -1 ){
            perror("[EROARE FIU2]Nu am putut deschide fisierul prenume.txt !\n");
            return 3;
        }

        while(fgets(line, sizeof(line), file)){
            // eliminam new-line
            int aux = 0;
            while(line[aux] != '\n'){
                aux++;
            }
            line[aux] = '\0';

            // asteptam sa ni se permita sa scriem
            read(pip_1_to_2[0], &ch, sizeof(ch));
            printf("[FIU2 ] Trebuie scris  : %s \n", line);

            /* write(fout, &line, strlen(line)); */
            fprintf(file_out,"%s \n", line);
            fflush(file_out);

            // dam voie celuilalt proces sa scrie
            ch = 'o';
            write(pip_2_to_1[1], &ch, sizeof(ch));
        }

        if(!feof(file)){
            perror("[EROARE FIU2] Nu am ajuns la finaul fisierului prenume.txt !\n");
            return 5;
        }



        close(pip_1_to_2[0]);
        close(pip_2_to_1[1]);
        fclose(file);
        close(fin);

        fclose(file_out);
        close(fout);

        return 0;
    }

    // ================================================================================
    // PARINTE
    
    // permitem primului fiu sa scrie
    ch = 'o';
    write(pip_2_to_1[1], &ch, sizeof(ch));
    
    /*  Inchidem sa nu fie probleme  */
    // pipe 1 to 2
    close(pip_1_to_2[0]);
    close(pip_1_to_2[1]);
    // pipe 2 to 1
    close(pip_2_to_1[0]);
    close(pip_2_to_1[1]);

    fclose(file_out);
    close(fout);

    wait(NULL); // asteptam ambi fii
    printf("[PARINTE] END !\n ");

    return 0;
}
