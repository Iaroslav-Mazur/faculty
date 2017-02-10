#include "Matrice.h"
#include <iostream>

Matrice::Matrice(){
    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            this->Matrix[i][j] = 0;

};

Matrice::Matrice(int **array){
    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            this->Matrix[i][j] = array[i][j];
            // this->Matrice[i][j] = *(i * 3 + j);
}



void Matrice::Print(){
    for(int i =0; i < 3; i++){
        for(int j =0; j < 3; j++)
            std::cout << this->Matrix[i][j] << " ";

    std::cout << std::endl;
    }
}


Matrice Matrice::operator - (const Matrice &operand){
   Matrice out; 

    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            out.Matrix[i][j] = this->Matrix[i][j] - operand.Matrix[i][j];

    return out;
}

Matrice Matrice::operator + (const Matrice &operand){
   Matrice out; 

    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            out.Matrix[i][j] = this->Matrix[i][j] + operand.Matrix[i][j];

    return out;
}

Matrice& Matrice::operator = (Matrice &m){
    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
            this->Matrix[i][j] = m.Matrix[i][j];

    return *this;
}

Matrice::Matrice(const Matrice &altaMatrice){
    for(int i =0; i < 3; i++)
        for(int j =0; j < 3; j++)
                this->Matrix[i][j] = altaMatrice.Matrix[i][j];
}


int operator ~ (const Matrice &m){
    int out;
    out = m.Matrix[0][0] * m.Matrix[1][1] * m.Matrix[2][2];

    out += m.Matrix[1][0] * m.Matrix[0][2] * m.Matrix[2][1];

    out += m.Matrix[0][2] * m.Matrix[1][2] * m.Matrix[2][0];


    out -= m.Matrix[0][2] * m.Matrix[1][1] * m.Matrix[2][0];

    out -= m.Matrix[1][0] * m.Matrix[0][1] * m.Matrix[2][2];

    out -= m.Matrix[2][1] * m.Matrix[1][2] * m.Matrix[0][0];
    return out ;
}


Matrice operator ! (const Matrice &m){
    Matrice mat;
    mat.Matrix[0][0] = m.Matrix[0][0];
    mat.Matrix[0][1] = m.Matrix[1][0];
    mat.Matrix[0][2] = m.Matrix[2][0];
    mat.Matrix[1][0] = m.Matrix[0][1];
    mat.Matrix[1][1] = m.Matrix[1][1];
    mat.Matrix[1][2] = m.Matrix[2][1];
    mat.Matrix[2][0] = m.Matrix[0][2];
    mat.Matrix[2][1] = m.Matrix[1][2];
    mat.Matrix[2][2] = m.Matrix[2][2];
    return mat;
}

bool operator == (const Matrice &m1, const Matrice &m2){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(m1.Matrix[i][j] != m2.Matrix[i][j]) 
                return false;
   
    return true;
}

