class Punct
{
private:
	//[1p] Coordonatele punctului.

public:
	//[1p] Constructorul implicit care plaseaza punctul în origine.
	Punct();
		
	//[1p] Constructorul cu parametri.
	Punct(int x,int y);

	//[1p] Resetarea coordonatelor la (0,0).
	void reset();

	//[1p] Returneaza coordonata X a punctului.
	int getX();

	//[1p] Returneaza coordonata Y a punctului.
	int getY();
	
	//[1p] Seteaza coordonata X a punctului.
	void setX(int x);

	//[1p] Seteaza coordonata Y a punctului.
	void setY(int y);
};