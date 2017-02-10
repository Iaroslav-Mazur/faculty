#include "Hartie.h"
#include <iostream>

Hartie::Hartie(Informatie* parent, int x, int y, std::string mesaj, std::string culoare){
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->mesaj = mesaj;
    this->color = culoare;
}

void Hartie::Print(){
    std::cout << "Hartie si ceva info \n";
    for(int i = 0; i < this->colection.size(); i++){
        this->colection[i]->Print();
    }
}

void Hartie::Agauga(Informatie* attach){
    this->colection.push_back(attach);
}

int Hartie::GetTop(){
    int val = this->x;
    if(this->parent){
        val += this->parent->GetTop();
    }
    return val;
}

int Hartie::GetLeft(){
    int val = this->x;
    if(this->parent){
        val += this->parent->GetLeft();
    }
    return val;
}

std::string Hartie::GetText(){
    return this->mesaj;
}



