// #include "singelton.h"
#include "singelton.h"
#include "singelton2.h"
#include <iostream>


int main(){
    Singeltone *p1 = Singeltone::newClass();
    Singeltone *p2 = Singeltone::newClass();
    Singeltone *p3 = Singeltone::newClass();
    Singeltone *p4 = Singeltone::newClass();

    Singeltone2 &pp1 = Singeltone2::newClass();
    Singeltone2 &pp2 = Singeltone2::newClass();
    Singeltone2 &pp3 = Singeltone2::newClass();
    Singeltone2 &pp4 = Singeltone2::newClass();

    std::cout  << "S1 :" << Singeltone::count << std::endl;
    std::cout  << "S2 :" << Singeltone2::count << std::endl;
    return 0;
}
