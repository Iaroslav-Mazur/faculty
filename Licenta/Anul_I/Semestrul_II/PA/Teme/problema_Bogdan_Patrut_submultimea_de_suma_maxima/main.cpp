#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

#define MAX_SIZE 128

int N, SUM;
vector< pair<int,int> > elemente;
bool FOUND = false;

void help(){
    printf("Utilizare ./main <suma> <nr_argumente> <n1> <n2> <n3> ....\n ");
    printf("suma         - la care dorim sa ajungem \n");
    printf("nr_argumente - cate argumente are multimeaj\n");
    printf("n1, n2 ...   - elementele multimi \n");
}

void print_elemente(){
    for(int i = 0; i < elemente.size(); i++){
        printf("%d - %d \n", elemente[i].first, elemente[i].second);
    }
}
int get_sum(){
    int aux = 0;
    for(int i = 0; i < elemente.size(); i++){
        pair<int, int> elem = elemente[i];
        aux += elem.first * elem.second;
    }
    return aux;
}
void print_bin(){
    for(int i = 0; i < elemente.size(); i++){
        printf("%d ", elemente[i].first);
    }
    printf("   |  %d  | ", get_sum());
}


bool can_be_sol(int poz){
    int aux = 0;
    for(int i = 0; i < elemente.size(); i++){
        pair<int, int> elem = elemente[i];
        aux = elem.first * elem.second;
    }

    return( aux <= SUM);
}

bool este_sol(int poz){
    int aux = 0;
    for(int i = 0; i < elemente.size(); i++){
        pair<int, int> elem = elemente[i];
        aux += elem.first * elem.second;
    }

    return(aux == SUM);
}

void victorie(){
    if(FOUND){
        return ;
    }
    printf("Am gasit o solutie ! \n");

    printf("Elementele de care avem nevoie sunt : \n");
    for(int i = 0; i < elemente.size(); i++){
        pair<int, int> elem = elemente[i];
        if(elem.first == 1){
            printf("%d ", elem.second);
        }
    }
    FOUND = true;
}

void backtraking(int poz){
    // printf("BKT %d : %d | %d \n", poz, poz > elemente.size(), ! FOUND);
    if(poz > elemente.size() || FOUND){
        return ;
    }

    // printf("~BKT %d \n", poz);

    if(can_be_sol(poz)){
        for(int i = 0; i < 2; i++){
            elemente[poz].first = i;

            if(este_sol(poz)){
                victorie();
            }else{
                backtraking(poz+1);
            }
        }
        elemente[poz].first = 0;
    }
    
}

int main(int argc, char *argv[])
{

    if(argc < 2){
        printf("[EROARE] Avem nevoie de mai multi parametri. Given %d !\n", argc);
        help();
        return 1;
    }

    SUM = atoi(argv[1]);
    N = atoi(argv[2]);

    if(argc < 2 + N ){
        printf("[EROARE] Avem nevoie de mai multi parametri. Given %d !\n", argc);
        printf("[EROARE] Avem nevoie de toate elementele pentru multime! \n");
        help();
        return 2;
    }

    if(N > MAX_SIZE){
        printf("[EROARE] Prea multe elemente in multime! \n");
        help();
        return 2;
    }

    // citim elementele
    pair<int, int> aux;
    for(int i = 0; i < N; i++){
        aux.first = 0;
        aux.second = atoi(argv[2 + i]);
        elemente.push_back(aux);
    }

    backtraking(0);
    if(! FOUND){
        printf("Nu am putut gasi o combinatie care sa fie egala cu suma data (%d)\n", SUM);
    }

    return 0;
}
