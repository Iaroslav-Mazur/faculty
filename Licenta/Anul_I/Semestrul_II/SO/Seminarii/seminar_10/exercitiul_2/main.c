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
    if(argc < 0){
        char aux[100];
        printf("Care este directorul :");
        scanf("%s", aux);
        dir = aux;
    }else{
        dir = argv[1];
    }

    printf("Path este :%s \n", dir);
    
    return 0;
}
