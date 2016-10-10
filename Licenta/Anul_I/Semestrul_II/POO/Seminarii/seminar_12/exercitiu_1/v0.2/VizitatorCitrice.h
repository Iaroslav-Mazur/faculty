#include "Vizitator.h"
#ifndef VIZITATOR_CITRICE_H_
#define VIZITATOR_CITRICE_H_ value

class VizitatorCitrice: public Vizitator{
    public:
        virtual void viziteaza(Fruct* f) = 0;
        virtual char* getName() = 0
};
#endif /* ifndef VIZITATOR_CITRICE_H_ */
