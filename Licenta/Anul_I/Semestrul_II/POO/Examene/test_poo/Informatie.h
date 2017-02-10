#ifndef INFORMATIE_H_
#define INFORMATIE_H_ value
#include <string>

class Informatie{
    public:
        virtual void Print() = 0;
        virtual void Agauga(Informatie* attach) = 0;
        virtual int GetTop() = 0;
        virtual int GetLeft() = 0;
        virtual std::string GetText() = 0;
};
#endif /* ifndef INFORMATIE_H_ */
