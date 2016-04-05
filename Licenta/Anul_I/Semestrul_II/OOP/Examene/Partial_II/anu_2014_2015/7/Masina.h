class Masina
{
private:
	//[2p] Adaugati Caracteristici masina.

public:
	//[3p] Returneaza an de fabricatie al masinii. -> cate 1p pentru implementarea din fiecare clasa derivata
	virtual int getAn_fabricatie()=0;

	//[3p] Returneaza culoarea masinii. -> cate 1p pentru implementarea din fiecare clasa derivata
	virtual string getCuloare()=0;

        //[3p] Returneaza viteza maxima a masinii. -> cate 1p pentru implementarea din fiecare clasa derivata
	virtual int getViteza_maxima()=0;
 
	//[3p] Seteaza numele masinii -> cate 1p pentru implementarea din fiecare clasa derivata
	virtual void setNume(string name)=0;	

        //[3p] Returneaza numele masinii. -> cate 1p pentru implementarea din fiecare clasa derivata
        virtual string getNume()=0;	
};

