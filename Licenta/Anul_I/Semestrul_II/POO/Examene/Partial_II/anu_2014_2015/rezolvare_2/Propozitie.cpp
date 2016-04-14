#include "Propozitie.h"

Propozitie::Propozitie(){
    this->propozitie = string("");
}

Propozitie::Propozitie(const char *c){
    this->SetPropozitie(c);
}

bool Propozitie::SetPropozitie(const char *c){
    string my_str(c);
    // eliminam spatiile de la inceput
    while(my_str.length() > 0 && my_str[0] == ' '){
        my_str.erase(0, 1);
    }

    while(my_str.length() > 0 && my_str[0] == ' '){
        my_str.erase(my_str.length()- 1, 1);
    }

    string spaces("  ");
    size_t point = my_str.find(spaces);
    while(point  != string::npos){
        my_str.erase(point, 1);
        point = my_str.find(spaces);
    }

    if( my_str[my_str.length()-1] != '.' ){
        return false;
    }

    string::iterator it;
    string s("");
    for(it = my_str.begin(); it != my_str.end(); it++){
        if(' ' == (char)(*it)){
            this->words.push_back(s);
        }else{
            string aux((char*)(*it));
            s += s + aux;
        }
    }

    // validam cuvintele
    for(int i = 0; i < this->words.size(); i++){
        for(int j = 0; j < this->words[i].length(); j++){
            if(
                    (this->words[i][j] < 'a' || this->words[i][j] > 'z')
                    &&
                    (this->words[i][j] < 'A' || this->words[i][j] > 'Z')
              ){
                this->words.clear();
                this->propozitie = string("");
                return false;
            }
        }
    }

    this->propozitie = string(c);

    return true;
}


