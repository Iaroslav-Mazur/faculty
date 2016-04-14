#include <iostream>
#include <cstring>
#include <stdio.h> 
#include <cerrno>
using namespace std;
#define FILENAME "data.txt"

char *read_line(FILE *file, int &error){

    return NULL;
}

void sortare()
int main(){
    FILE * f;
    f = fopen(FILENAME, "r");
    if(!f){
        printf("Nu am putut deschide fisier. Eroare : %d", errno);
        fclose(f);
        return 1;
    }

    char lines[1000][100];

    int i = 0;
    while(fgets(lines[i++], 100, f) != NULL){
        // filter new lines
        for(char *c = &lines[i][0]; *c != '\0'; c++){
            if(*c == '\n'){
                *c = '\0';
            }
        }
    }

    // in cazul in care fgets are o eraore de citire
    if(ferror(f)){
        printf("A aparut o eroare la citirea din fisier !");
        fclose(f);
    }


    fclose(f);
    return 0;
}
