#include "singelton.h"
#include <iostream>

Singeltone*  Singeltone::p = 0;
int Singeltone::count = 0;
 

Singeltone::Singeltone(){
    std::cout << "Instanta s" << std::endl;
    Singeltone::p  = this;
    Singeltone::count += 1;
}

Singeltone::~Singeltone(){
    std::cout << "Distruge S" << std::endl;
    Singeltone::p = 0; 
}

Singeltone* Singeltone::newClass(){
    if( ! Singeltone::p) {
        Singeltone::p = new Singeltone();
    }

    return Singeltone::p;
}

