#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cerrno>

using namespace std;

char *v[1000];

void readFromFile(char *filename){
    FILE *file;
    file = fopen(filename, "r");

    if(!file){
        cout << "Nu s-a putut deschide fisierul " << errno << endl;
    }

    // while(!feof(file)){
    //     char *c;
    //     
    // }
    
    cout << "here " << endl;
    while(fgetc(file) != EOF){
        char *line;
        fgets(line, 1000, file);
        cout << "here " << endl;
        cout << line << endl;
    }

    
}

int main(){
    char *c = "data.txt";
    readFromFile(c);
}
