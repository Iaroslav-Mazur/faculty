#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
using namespace std;

#define MAX_SIZE 100
typedef pair<int, int> point;

struct Matrice {
    int lines, columns;
    int values[MAX_SIZE][MAX_SIZE];
};

void citire_matrice(const char *filename, Matrice &m){
    ifstream file(filename);
    file >> m.lines;
    file >> m.columns;

    for(int i = 0; i < m.lines; i++)
        for(int j = 0; j < m.lines; j++){
            file >> m.values[i][j];
        }

    file.close();
}

bool it_matches(Matrice &big, Matrice &pattern, int x, int y){
    for(int i = 0; i < pattern.lines; i++)
        for(int j = 0; j < pattern.columns; j++){
            if( big.values[x + i][y + j] != pattern.values[i][j])
                return false;
        }

    return true;
}


point* search(Matrice &bigM, Matrice &patternM){
    point *p;
    p = new point;
    p->first = -1;
    p->second= -1;


    for(int i = 0; i < bigM.lines - patternM.lines; i++)
        for(int j = 0; j < bigM.columns- patternM.columns; j++){
            if(it_matches(bigM, patternM, i, j)){
                p->first = i;
                p->second= j;
                return p;
            }
        }

    return p;
}


int main(){
    Matrice bigM, patternM;

    citire_matrice("bigM.txt", bigM);
    citire_matrice("patternM.txt", patternM);

    point *p;
    p = search(bigM, patternM);
    

    cout << p->first << " - " << p->second << endl;
    return 0;
}

