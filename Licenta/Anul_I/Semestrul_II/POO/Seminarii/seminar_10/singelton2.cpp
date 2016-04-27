#include "singelton2.h"
#include <iostream>

int Singeltone2::count = 0;

Singeltone2::Singeltone2(){
    Singeltone2::count += 1;
    std::cout << "Instanta S2" << std::endl;
}

Singeltone2::~Singeltone2(){
    Singeltone2::count = 0;
    std::cout << "Distruge S2" << std::endl;
}


Singeltone2& Singeltone2::newClass(){
    static Singeltone2 x;

    return x;
}
