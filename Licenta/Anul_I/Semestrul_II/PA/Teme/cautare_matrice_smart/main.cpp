#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
using namespace std;

#define MAX_SIZE 100
#define BAZA 24
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

int get_itm(int x){
    if(x == 0){
        return BAZA;
    }
    return x*BAZA;
}

int get_hash(Matrice &m, int x, int y,int lines, int columns){
    int hash = 1;
    for(int i = x; i < lines; i++)
        for(int j = x; j < columns; j++){
            hash *= get_itm(m.values[i][j]);
        }
    return hash;
}

int update_hash_right(Matrice &m, int x, int y, int last_hash, int lines, int columns){
    for(int i = x; i < m.lines; i++){
        last_hash /= get_itm(m.values[i][y-1]);
        last_hash *= get_itm(m.values[i][y+m.columns]);
    }
    return last_hash;
}

int update_hash_down(Matrice &m, int x, int y, int last_hash, int lines, int columns){
    for(int i = x; i < m.columns; i++){
        last_hash /= get_itm(m.values[x-1][i]);
        last_hash *= get_itm(m.values[x+m.lines][i]);
    }
    return last_hash;
}

point* search(Matrice &bigM, Matrice &patternM){
    point *p;
    p = new point;
    p->first = -1;
    p->second= -1;
    int hash_pattern = get_hash(patternM, 0, 0, patternM.lines, patternM.columns),
        hash = get_hash(bigM, 0, 0, patternM.lines, patternM.columns);

    int i, j;
    for(i = 0; i < bigM.lines - patternM.lines; i++){
        for(j = 0; j < bigM.columns- patternM.columns; j++){
            if(hash_pattern == hash)
                if(it_matches(bigM, patternM, i, j)){
                    p->first = i;
                    p->second= j;
                    return p;
                }
            hash = update_hash_right(bigM, i, j+1, hash, patternM.lines, patternM.columns);
        }
        hash = update_hash_down(bigM, i+1, j, hash, patternM.lines, patternM.columns);
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

