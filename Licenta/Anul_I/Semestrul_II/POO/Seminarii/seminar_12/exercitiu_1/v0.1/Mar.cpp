#include "Fruct.cpp"
#include <iostream>
#ifndef MAR_H_
#define MAR_H_ value

class Mar: private Fruct{
    public:
        Mar(int volum, int vit_c);
        char* getNume(){
            return "Mar";
        }
};
#endif /* ifndef MAR_H_ */

Mar::Mar(int volum, int vit_c): Fruct(volum, vit_c){
    std::cout << "Constructor Mar " << std::endl;
}


