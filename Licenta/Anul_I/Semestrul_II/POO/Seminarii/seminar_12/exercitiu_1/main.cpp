#include <iostream>
using namespace std;

class Fruct;
class Mar;
class Portocala;

class Vizitator{
    public:
        virtual void viziteaza(Mar * f) = 0;
        virtual void viziteaza(Portocala * f) = 0;
};

// Fruct
class Fruct{
    protected:
        int val;
    public:
        virtual char* getName() = 0;
        virtual void accept(Vizitator* v) = 0;
};




class Mar: public Fruct{
    public:
        Mar(int i){
            val = i;
        }
        virtual char* getName(){
            return "Mar";
        }
        virtual void accept(Vizitator* v){
            v->viziteaza(this);
        }
};

class Portocala: public Fruct{
    public:
        Portocala(int i){
            val = i;
        }
        virtual char* getName(){
            return "Portocala";
        }
        virtual void accept(Vizitator* v){
            v->viziteaza(this);
        }
};

class VizitatorCitrice: public Vizitator{
    public:
        virtual void viziteaza(Mar *f){
            cout << "Vizitator citrice : \n";
            cout << "Vizitam :" << f->getName() << endl;
        }
        virtual void viziteaza(Portocala *f){
            cout << "Vizitator citrice : \n";
            cout << "Vizitam :" << f->getName() << endl;
        }
};


int main(){
    Portocala p1(10), p2(20);
    Mar m1(1), m2(2);

    VizitatorCitrice viz;
    viz.viziteaza(&p1);
    viz.viziteaza(&p2);

    viz.viziteaza(&m1);
    viz.viziteaza(&m2);

    return 0;
}
