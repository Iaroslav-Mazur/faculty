#include "Vizitator.cpp"
#include <iostream>


#ifndef VIZITATORCALCULATOR_H_
#define VIZITATORCALCULATOR_H_ value

class VizitatorCalculator: public Vizitator {
    public:
        int vizit(Fruct &f){
            std::cout << "Vizitam un fruct ! \n";
            return f.volum * f.vitamina_c;
        }
};

#endif /* ifndef VIZITATORCALCULATOR_H_ */
