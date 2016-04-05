#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
#define M_H 6
#define M_W 5

int dist(int x1, int y1,int x2,int y2){
    //ceeling
    return (sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}

void circle(int *p, int x, int y, int r){
    int i, j;
    for(i = 0; i < M_H; i++)
        for(j = 0; j < M_W; j++)
            if(dist(i, j, x, y) == r)
                *(p + (i*M_W) + j) = 1;
}

void afis(int *p){
    int i, j;
    for(i = 0; i < M_H; i++){
        for(j = 0; j < M_W; j++)
            cout << *(p + (i*M_W) + j) << " ";
        cout << endl;
    }
}

int main(){
    int *p = new int[30];
    memset(p, 0, 30);

    circle(p, 2, 2, 2);
    afis(p);

    return 0;
}
