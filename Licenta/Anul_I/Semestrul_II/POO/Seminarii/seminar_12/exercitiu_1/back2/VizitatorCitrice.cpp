#include <iostream>
#include "VizitatorCitrice.h"

void VizitatorCitrice::viziteaza(Fruct* f){
    std::cout << "Vizitator Citrice \n";

    std::cout << "Vizitam :" << f->getName() <<"\n";
    std::cout << "Valoarea :" << f->valoare <<"\n";
}
char* VizitatorCitrice::getName(){
    return "Vizitator Citrice";
}
