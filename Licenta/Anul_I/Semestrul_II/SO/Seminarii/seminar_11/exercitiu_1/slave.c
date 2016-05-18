#include <stdlib.h>
#include <stdio.h>
/* #include <string.h> */


int main(int argc, char *argv[])
{

    /* printf("Am apelat slavul cu %d \n", argc); */
    /* //params */
    /* int i; */
    /* for(i = 1; i < argc; i++){ */
    /*     printf("[ %d ] %s \n",i, argv[i]); */
    /* } */

    if(argc < 4){
        exit(0);
    }

    int a = atoi(argv[1]),
        b = atoi(argv[2]),
        rezult = 0;

    if((char)*argv[3] == '-'){
        rezult = a - b;
        /* printf("Rezultat %d \n", rezult); */
        exit(rezult);
    }

    if((char)*argv[3] == '+'){
        rezult = a + b;
        /* printf("Rezultat %d \n", rezult); */
        exit(rezult);
    }

    printf("Something bad happened \n");
    return 0;
}
