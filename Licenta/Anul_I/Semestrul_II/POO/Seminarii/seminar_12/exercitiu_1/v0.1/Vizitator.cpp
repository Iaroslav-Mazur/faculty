#include <iostream>
#include "Fruct.cpp"
#ifndef VIZITATOR_H_
#define VIZITATOR_H_ value

class Vizitator{
    public:
        virtual int vizit(Fruct &f) = 0;
};

#endif /* ifndef VIZITATOR_H_ */
