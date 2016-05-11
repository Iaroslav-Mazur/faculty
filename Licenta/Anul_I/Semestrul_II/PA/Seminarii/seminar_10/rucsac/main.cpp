#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Obiect{
    float id, volum, valoare, procent;
};

float get_raport(Obiect &o){
    return o.valoare / o.volum;
}

int main(){
    fstream file("date.txt");
    float volum, n;
    file >> volum;
    file >> n ;

    vector<Obiect> rucsac, inventar;

    for(int i = 0; i < n; i++){
        Obiect aux;
        aux.id = i;
        file >> aux.volum;
        file >> aux.valoare;

        inventar.push_back(aux);
    }

    // ordonare
    for(int i = 0; i < inventar.size()-1; i++){
        for(int j = i + 1; i < inventar.size(); i++){
            if(get_raport(inventar[i]) < get_raport(inventar[j])){
                Obiect aux;
                aux = inventar[i];
                inventar[i] = inventar[j];
                inventar[j] = aux;
            }
        }
    }

    int i=0;
    while(volum > 0){
        if(volum > inventar[i].volum){
            inventar[i].procent = 1;
            rucsac.push_back(inventar[i]);
            volum -= inventar[i].volum;
            i++;
        }
        else
        {
            float procent = volum / inventar[i].volum;
            inventar[i].procent = procent;
            rucsac.push_back(inventar[i]);

        }
    }

    // calcul profit
    float profit = 0;
    for(int i = 0; rucsac.size(); i++){
        profit += rucsac[i].valoare * rucsac[i].procent;
    }

    cout << "Profit :" << profit << endl;


    file.close();
    return 0;
}
