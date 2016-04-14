class Translate
{
private:
	//[1p] membri privati - ii adaugati voi
public:
	//[1p] initializeaza clasa
	Translate();

	//[3p] - adauga o lista pentru traduceri. Returneaza true daca cuvintele din lista sunt unice si nenule
	bool AddTranslate(vector<pair<const char*,const char*>>& lista);

	//[1p] - adauga o traducere dintr-un cuvant in altul. Returneaza true daca cuvant1 nu a fost adaugat pana acuma si cuvant1 si cuvant2 sunt nenule
	bool AddTranslate(const char *cuvant1,const char* cuvant2);

	//[1p] - retruneaza traducerea pentru un cuvant (daca exista) sau NULL altfel
	const char* GetTranslate(const char *cuvant);

	//[1p] - returneaza numarul de cuvinte care sunt traduse
	int GetCount();

	//[6p] - inverseaza cheia cu valoare de la fiecare element din dictionar
	void ReverseTranslate();

	//[9p] - returneaza textul tradus; se pot folosi find si substr din string STL pt extragerea cuvintelor
	string DoTranslate(const char* text);
}