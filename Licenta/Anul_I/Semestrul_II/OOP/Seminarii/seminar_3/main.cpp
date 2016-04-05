#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class BigNumber {
   private:
      char Number[256];
      int  CharactersCount;
   public:
      BigNumber (); // Constructor implicit
      BigNumber (int value); 
      BigNumber (const char * number); // Constructor de copiere
      bool Set(int value);
      bool Set(const char * number);
      BigNumber operator+ (const BigNumber & number);
      BigNumber operator* (const BigNumber & number);
      BigNumber operator- (const BigNumber & number);
      BigNumber operator/ (const BigNumber & number);
      friend bool operator == (const BigNumber & n1, const BigNumber & n2);
      friend bool operator != (const BigNumber & n1, const BigNumber & n2);
      friend bool operator <  (const BigNumber & n1, const BigNumber & n2);
      friend bool operator >  (const BigNumber & n1, const BigNumber & n2);
      friend bool operator >= (const BigNumber & n1, const BigNumber & n2);
      friend bool operator <= (const BigNumber & n1, const BigNumber & n2);
      operator const int();
      char operator[] (int index); // returneaza caracterul de pe pozitia index sau \0 in rest
        BigNumber operator() (int start,int end); // returneaza subnumarul de la caracterul start pana la caracterul index sau "0" daca start/index nu sunt valide.
};

// Constructori 
BigNumber::BigNumber():CharactersCount(1) {
    this->Number[0] = 0;
}

BigNumber::BigNumber(int value) {
    this->Set(value);
}
BigNumber::BigNumber(const char * number) {
    this->Set(number);
}

bool BigNumber::Set(int value){
    this->CharactersCount = 0;
    this->Number[0] = 0;
    while(value){
        char c = value % 10;
        this->Number[this->CharactersCount++] = c;
        value = value / 10;
    }
    return true;
}

bool BigNumber::Set(const char * number){
    int i = 0;
    while(this->Number[i] != '\0')
        this->CharactersCount = i;

    for(i = 0; number[i] != '\0'; i++){
        this->Number[this->CharactersCount-1] = number[i];
    }
    return true;
}

BigNumber BigNumber::operator+ (const BigNumber & number){
    char nr[256], transport = 0;
    char max = (this->CharactersCount > number.CharactersCount) ? this->CharactersCount : number.CharactersCount;
    char min = (this->CharactersCount < number.CharactersCount) ? this->CharactersCount : number.CharactersCount;
    for(int i = 0; i < min ; i++){
        char n;
        n = this->Number[i] + number.Number[i] + transport;
        transport = n % 10;
        nr[i] = transport /10;
    }
    // BigNumber aux = number;
    // BigNumber &p = (this->CharactersCount == max) ? *this : ;
    if(this->CharactersCount != min ){
        for(int i = min+1; i < max; i++){
            char n;
            n = this->Number[i] + transport;
            transport = n % 10;
            nr[i] = transport / 10;
        }
    }else{
        for(int i = min+1; i < max; i++){
            char n;
            n = this->Number[i] + transport;
            transport = n % 10;
            nr[i] = transport / 10;
        }
    }

    if(transport){
        nr[max++] = transport;
    }

    nr[max] = '\0';
    BigNumber b(nr);
    return b;
}


int main(){
    BigNumber a(10), b(12), c;
    c = a + b;

    return 0;
}
