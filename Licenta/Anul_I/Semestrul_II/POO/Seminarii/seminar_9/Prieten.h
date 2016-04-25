#include "Contact.h"
#include <ctime>

struct Addresa{
    string strada, tara, judet;
    int nr;
}


class Prieten: public Contact {
    public:
        string numar, data;
        Addresa addresa;
}
