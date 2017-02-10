#ifndef HARTIE_H_
#define HARTIE_H_ value
#include "Informatie.h"
#include <vector>
#include <string>


class Hartie: public Informatie{
        std::vector< Informatie* > colection;
        std::string color, mesaj;
        Informatie* parent;
        int x, y;
    
    public:
        virtual void Print();
        virtual void Agauga(Informatie* attach);
        virtual int GetTop();
        virtual int GetLeft();
        virtual std::string GetText();
        Hartie(Informatie* parent, int x, int y, std::string mesaj, std::string culoare);
};

#endif /* ifndef HARTIE_H_ */
