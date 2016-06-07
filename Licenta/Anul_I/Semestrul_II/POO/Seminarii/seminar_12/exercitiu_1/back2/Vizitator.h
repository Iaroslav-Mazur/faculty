
#ifndef VIZITATOR_H_
#define VIZITATOR_H_ value

#include "Fruct.h"
class Vizitator{
    public:
        virtual void viziteaza(Fruct* f) = 0;
        virtual char* getName() = 0;
};
#endif /* ifndef VIZITATOR_H_ */
