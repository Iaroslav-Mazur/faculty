#include "Sticker.h"
#include <iostream>

Sticker::Sticker(Informatie* parent, int x, int y, std::string mesaj, std::string culoare){
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->mesaj = mesaj;
    this->color = culoare;
}

void Sticker::Print(){
    std::cout << "Sticker si ceva info\n";
    for(int i = 0; i < this->colection.size(); i++){
        this->colection[i]->Print();
    }
}

void Sticker::Agauga(Informatie* attach){
    this->colection.push_back(attach);
}

int Sticker::GetTop(){
    int val = this->x;
    if(this->parent){
        val += this->parent->GetTop();
    }
    return val;
}

int Sticker::GetLeft(){
    int val = this->x;
    if(this->parent){
        val += this->parent->GetLeft();
    }
    return val;
}

std::string Sticker::GetText(){
    return this->mesaj;
}

