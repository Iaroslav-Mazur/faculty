#ifndef FRUCT_H_
#define FRUCT_H_ value
#include "Vizitator.cpp"

class Fruct {
    private:
        int volum, vitamina_c;

    public:
        Fruct(int volum, int vit_c);
        virtual char* getNume() = 0;
        int accept(Vizitator &v);
};

Fruct::Fruct(int volum, int vit_c){
    std::cout << "Constructor Fruct " << std::endl;
    this->volum = volum;
    this->vitamina_c = vit_c;
}

int Fruct::accept(Vizitator &v){
    return v.vizit(this);
}




#endif /* ifndef FRUCT_H_ */
