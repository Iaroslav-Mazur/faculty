#include <iostream>
#include <vector>

using namespace std;

struct Moneda{
    int valoare, cantitate;
};

vector<Moneda> monede;
int cat_am_luat[100], cel_mai_bun[100], minim, cel_mai_bun_n;
int suma;

void citire(){
    cin >> suma;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        Moneda aux;
        cin >> aux.valoare;
        cin >> aux.cantitate;

        monede.push_back(aux);
    }
}

void afisare(){
    for(int i = 0; i < monede.size(); i++){
        cout << monede[i].valoare << " " << monede[i].cantitate << endl;
    }
}


bool solutie(int moneda){
    int aux = 0;
    for(int i = 0; i < moneda; i++){
        aux += cat_am_luat[moneda] * monede[moneda].valoare;
    }

    return (aux == suma);
    
}

bool can_work(int moneda){
    int aux = 0;
    for(int i = 0; i < moneda; i++){
        aux += cat_am_luat[moneda] * monede[moneda].valoare;
    }

    return (aux < suma);
}

void update(int moneda){
    int aux;

    for(int i = 0; i < moneda; i++){
        aux += cat_am_luat[moneda];
    }

    if( aux < minim ){
        // solutie buna
        cel_mai_bun_n = moneda;
        for(int i = 0 ;i < cel_mai_bun_n; i++){
            cel_mai_bun[i] = cat_am_luat[i];
        }
    }
    minim = aux;
}


void bkd(int moneda){
    if( moneda > monede.size() ) {
        return;
    }

    for(int i = 0; i < monede[moneda].cantitate; i++){
        cat_am_luat[i] = i;

        if(solutie(moneda)){
           update(moneda);
        }else{
            if(can_work(moneda)){
                bkd(moneda+1);
            }
        }

    }
}


int main(){
    cout << "Here "<< endl;
    citire();
    afisare();
    minim = 1000000;

    // maxim
    for(int i = 0; i < monede.size(); i++){
        cat_am_luat[i] = 0;
        cel_mai_bun[i] = 0;
    }

    cel_mai_bun_n = 0;

    bkd(0);

    cout << "Solutie " << endl;
    cout << "Nr monede :" << minim << endl;
    for(int i = 0; i < cel_mai_bun_n; i++){
        cout << "Am luat" << monede[i].valoare << " de " << cel_mai_bun[i] << endl;
    }

    return 0;
}
