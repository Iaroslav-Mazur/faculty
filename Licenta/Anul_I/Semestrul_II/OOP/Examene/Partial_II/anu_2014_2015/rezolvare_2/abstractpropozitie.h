#include<iostream>
#include<string>
#include<cstring>

using namespace std;
#ifndef AbstractPropozitie_H
#define AbstractPropozitie_H
class AbstractPropozitie
{
public:
	//[9p] creaza un obiect de tipul propozitie. Returneaza true daca sirul de caractere primit e o propozitie valida, false altfel
	virtual bool SetPropozitie(const char *) = 0;

	//[1p] returneaza numarul de cuvinte din propozite
	virtual int GetCount() = 0;

	//[1p] returneaza true daca un cuvant este in propozitie sau false altfel
	virtual bool ContainsWord(const char *word) = 0;

	//[1p] returneaza cuvintul corespunzator indexului sau NULL daca indexul este invalid
	virtual const char* GetWord(int index) = 0;

	//[5p] returneaza true daca propozitia curenta este are exact aceleasi cuvinte cu cea primita ca si parametru
	virtual bool HasSameWords(AbstractPropozitie &) = 0;

	//[4p] returneaza true daca este identica cu propozitia primita ca si parametru (aceleasi cuvinte in aceeasi ordine)
	virtual bool IsIdentical(AbstractPropozitie &) = 0;
};
#endif
