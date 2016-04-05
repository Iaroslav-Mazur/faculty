typedef struct _Specificatie{
	int an;
	string nume;
	int viteza_max;	
}Specificatie;

void main ()
{
	Masina **cars=(Masina*)malloc(6*sizeof(Masina*));
	string names[6]={"DAcia 1310","Dacia Logan","Renault C4","Renault C5","BMW X4","BMW X5"};
	
	cars[0]=(Masina*) new Dacia(1994,rosu,140);
	cars[1]=(Masina*) new Dacia(2004,gri,135);
	cars[2]=(Masina*) new Renault(2010,verde, 180);
	cars[3]=(Masina*) new Renault(2009,negru, 165);
	cars[4]=(Masina*) new BMW(2014,alba, 210);
	cars[5]=(Masina*) new BMW(1994,albastra, 190);
	  
	// Cream un vector de masini

	vector <Masina*> masini;	
	
	for (i=0;i<6;i++)
	{
		cars[i]->setNume(names[i]);
		masini.push_back(cars[i]);
	}
	
	//[2p] afisare caracteristici masini (parcurgere cu iterator)
	
	//[2p] Sortam vectorul crescator in functie de viteza
	
	//[2p] Sortam vectorul descrescator in functie de anul de fabricatie

}