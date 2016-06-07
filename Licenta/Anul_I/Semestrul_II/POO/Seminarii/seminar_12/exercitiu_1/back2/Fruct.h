
#ifndef FRUCT_H_
#define FRUCT_H_ value

#include "Vizitator.h"
class Fruct{
    public:
        void accepta(Vizitator& v);
    private:
        virtual char* getName() = 0;
        int valoare;
};
#endif /* ifndef FRUCT_H_ */
