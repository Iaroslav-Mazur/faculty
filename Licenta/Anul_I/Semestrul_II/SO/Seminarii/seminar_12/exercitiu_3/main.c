#include <unistd.h> // pipe, fork
#include <fcntl.h>
#include <stdio.h>


int main(){ 
    int pip[2];
    if(-1 == pipe(pip)){
        perror("[EROARE] Nu am putut crea pipe-ul \n");
        return 1;
    }
    

    int count = 0, aux;
    char ch[1024];
    fcntl(pip[1], F_SETFL, O_NONBLOCK);

    while(-1 != write(pip[1], &ch, sizeof(ch))){
        count += 1024;
    }

    printf("Am scris %d , adica %d KB   \n", count, count/1024);

    return 0;
}
