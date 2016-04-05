#include <iostream>
#include <cstdio> // open file
#include <string.h>
using namespace std;

#define NMAX 1000 
#define NR_MAX 256


int main(){

    char *numere[NMAX]; // vector de pointer de char
    int contor = 0;

    FILE *file;
    file = fopen("data.txt", "r");

    do {
        // aici filtram newline 
        numere[contor++] = new char[NR_MAX]; // alocam NR_MAX memorie 
        memset(numere[contor-1], 0, NR_MAX);
    }while(fgets(numere[contor-1], NR_MAX, file));


    for(int i = 0; i < contor - 1; i++)
        for(int j = 0; j < contor -i -1;j++){
            int x = strlen(numere[j]);
            int y = strlen(numere[j+1]);

            if(x < y || x == y && strcmp(numere[j], numere[j+1]) == 1){
                char *aux = numere[j];
                numere[j+1] = numere[j];
                numere[j+1] = aux;
            }
        }


    for(int i = 0; i < contor; i++){
        cout << numere[i] << endl;
    }

    return 0;
}
