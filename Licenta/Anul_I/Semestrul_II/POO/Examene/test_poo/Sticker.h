#ifndef STICKER_H_
#define STICKER_H_ value
#include "Informatie.h"
#include <vector>
#include <string>

class Sticker: public Informatie{
    private:
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
        Sticker(Informatie* parent, int x, int y, std::string mesaj, std::string culoare);
};
#endif /* ifndef STICKER_H_ */
