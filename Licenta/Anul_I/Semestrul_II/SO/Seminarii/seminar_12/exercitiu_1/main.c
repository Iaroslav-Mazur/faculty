#include <unistd.h> // pipe, fork
#include <fcntl.h> // pentru LOCK's
#include <errno.h> // pentru errno
#include <stdio.h> // pentru perror
#include <string.h> // pentru memset
#include <sys/types.h> // open
#include <sys/stat.h> // open
#include <sys/wait.h> // open

#define MAX_SIZE 1024

int main(){
    int pid1, pid2, pip_to_son_1[2], pip_to_son_2[2], pip_to_parent[2];
    char ch;

    // cream pipe-urile necesare
    if(-1 == pipe(pip_to_son_1)){
        perror("[EROARE] We could not open pipe for Son 1 \n ");
        return 7;
    }

    if(-1 == pipe(pip_to_son_2)){
        perror("[EROARE] We could not open pipe for parent-son2 ");
        return 6;
    }

    if(-1 == pipe(pip_to_parent)){
        perror("[EROARE] We could not open pipe for son2-parent  ");
        return 5;
    }


    // primul son 
    if(-1 == (pid1 = fork())){
        perror("[EROARE] Nu am putut crea primul son !");
        return 4;
    }

    if(! pid1){
        // suntem in primul son 
        
        close(pip_to_son_1[1]); // nu trebuie sa scriem in pipeul din care citim

        // pipeuri intre son2 - parinte
        close(pip_to_parent[0]);
        close(pip_to_parent[1]);

        close(pip_to_son_2[0]); // nu citim pe pipeul din care scriem

        while(read(pip_to_son_1[0], &ch, sizeof(ch)) != 0){
            /* printf("[FIU 1] Am primit : %c \n", ch); */

            if(ch >= 'a' && ch <= 'z'){
                /* printf("[FIU 1] Dau mai departe : %c \n", ch); */

                write(pip_to_son_2[1], &ch, sizeof(ch));
            }else{
                /* printf("[FIU 1] NU DAU MAI DEPARTE mai departe : %c \n", ch); */
            }
        }

        close(pip_to_son_2[1]); // permitem citirea de EOF


        // terminam primul son
        return 0;
    }


    // al doilea son  ------------------------------------------
    if(-1 == (pid2 = fork())){
        perror("[EROARE] Nu am putut crea al doilea son son !");
        return 3;
    }
    

    if(! pid2){
        // suntem in al doilea son
        
        close(pip_to_son_2[1]); // nu scriem in pipeul in care citim

        // pipeuri parinte-son1
        close(pip_to_son_1[0]);
        close(pip_to_son_1[1]);

        close(pip_to_parent[0]); // nu citim din pipeul in care scriem

        int lista[MAX_SIZE], dist = 0;
        char bf[2];
        bf[1] = '\n';


        memset(lista, 0, sizeof(lista)); // 0 peste tot

        int fout = open("statistici.txt", O_RDWR|O_CREAT);
        if( fout == -1 ){
            perror("[EROARE] Nu am putut crea fisierul statistici.txt");
            return 2;
        }

        while(read(pip_to_son_2[0], &ch, sizeof(ch)) != 0){
            /* printf("[FIU 2] Am primit : %c \n", ch); */

            lista[ch]++;
        }
        
        int i;
        for(i = 0; i < MAX_SIZE; i++){
            if(lista[i]){
                dist++; // litera distincta
                bf[0] = i;
                write(fout, &bf, sizeof(bf));
            }
        }

        close(fout);


       /////// 
        /* printf("[FIU 2] Afisam literele \n"); */
        /* for(i = 0; i < MAX_SIZE; i++){ */
        /*     if(lista[i]){ */
        /*         printf("[FIU 2] Litera <%c>  : %d \n", (char)i, i); */
        /*     } */
        /* } */
       /////// 


        // transmitem numarul de litere distincte
        /* printf("[FIU 2] Dam mai departe : %d \n", dist); */

        write(pip_to_parent[1], &dist, sizeof(dist));

        close(pip_to_parent[1]); // permitem citirea de EOF

        // terminam al doilea son
        return 0;
    }

    // suntem in parinte
    
    close(pip_to_son_2[0]);
    close(pip_to_son_2[1]);

    close(pip_to_son_1[0]); // nu citim de unde scriem

    close(pip_to_parent[1]); // nu scriem de unde citim

    int fin = open("date.txt", O_RDONLY);

    if( fin == -1 ){
        perror("[EROARE] Nu am putut deschide fisierul date.txt");
        return 1;
    }

    /* printf("[PARINTE] Incepe !\n"); */

    while(read(fin, &ch, sizeof(ch)) != 0){
        /* printf("[PARINTE] Am citit : %c \n", ch); */

        write(pip_to_son_1[1], &ch, sizeof(ch));
    }

    close(fin);
    close(pip_to_son_1[1]);


    int nr;
    read(pip_to_parent[0], &nr, sizeof(nr));
            
    printf("Am primit : %d \n", nr);

    /* TODO
     */

    return 0;
}
