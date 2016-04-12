#include "abstractpropozitie.h"
#include <vector>
#include <string>
using namespace std;

#ifndef _PROPOZITIE_H_
#define _PROPOZITIE_H_ 

typedef vector<string> strVec;


class Propozitie: public AbstractPropozitie {
    private:
        strVec words;
        string propozitie;
    public:
        Propozitie();
        Propozitie(const char *c);
        bool SetPropozitie(const char *c);
        int GetCount();
        bool ContainsWord(const char *word);
        const char* GetWord(int index);
        bool HasSameWords(AbstractPropozitie &itm);
        bool IsIdentical(AbstractPropozitie &itm);
};

#endif /* ifndef _PROPOZITIE_H_ */
