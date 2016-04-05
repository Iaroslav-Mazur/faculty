#include <iostream>
#include "class.h"
#include "math.h"
#include "stdlib.h"

/*
 * Obs.
 * Lab 5. Pe site greseala :
 * "creing" la problema 1
 */

using namespace std;

Dreptunghi::Dreptunghi(int lungime, int latime){
    this->Lungime = lungime ;
    this->Latime = latime;
}

double Dreptunghi::ComputeArea(){
    return (this->Lungime * this->Latime);
}

const char * Dreptunghi::GetName(){
    return "Dreptunghi";
}

Cerc::Cerc(int raza){
    this->Raza = raza;
}

double Cerc::ComputeArea(){
    return (2 * M_PI * this->Raza);
}

const char * Cerc::GetName(){
    return "Cerc";
}

Triunghi::Triunghi(int x1,int y1,int x2,int y2,int x3,int y3){
    this->X1 = x1;
    this->Y1 = y1;

    this->X2 = x2;
    this->Y2 = y2;

    this->X3 = x3;
    this->Y3 = y3;
}

double Triunghi::ComputeArea(){
    double d1, d2, d3, area, P, p;
    d1 = sqrt( pow(this->X1 - this->X2, 2) + pow(this->Y1 - this->Y2, 2) );
    d2 = sqrt( pow(this->X2 - this->X3, 2) + pow(this->Y2 - this->Y3, 2) );
    d3 = sqrt( pow(this->X3 - this->X1, 2) + pow(this->Y3 - this->Y1, 2) );
    P = d1 + d2 + d3;
    p = P / 2;

    area = sqrt( p*(p-d1)*(p-d2)*(p-d3) );

    return area;
}

const char * Triunghi::GetName(){
    return "Triunghi";
}

int main(){
    Dreptunghi d(10, 2);
    Cerc c(10);
    Triunghi t(1, 1, 1, 2, 2, 1);

    cout << d.GetName() << endl;
    cout << d.ComputeArea() << endl << endl;

    cout << c.GetName() << endl;
    cout << c.ComputeArea() << endl << endl;

    cout << t.GetName() << endl;
    cout << t.ComputeArea() << endl << endl;

    cout << "--------------" << endl << endl;

    Forma* vec[3];

    vec[0] = &d;
    vec[1] = &c;
    vec[2] = &t;

    for(int i = 0; i < 3; i++){
        cout << "Elementul :" << i << endl;
        cout << vec[i]->GetName() << endl;
        cout << vec[i]->ComputeArea() << endl << endl;
    }

    cout << endl;

    return 0;
}
