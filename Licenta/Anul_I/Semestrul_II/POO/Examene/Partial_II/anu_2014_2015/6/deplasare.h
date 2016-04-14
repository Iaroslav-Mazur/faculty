class Deplasare
{
private:
	vector<pair<char, int>> commands; 
public:
	//[1p] initializeaza clasa si seteaza coordonatele curente la (0,0)
	Deplasare();

	//[5p] - adauga o comanda; comanda poate fi:
	// l - left
	// r - right
	// t - top
	// b - bottom
	//functia returneaza false daca nu se da una din comenzile de mai sus sau daca offsetul este 0
	bool AddCommand(char command, int offset);

	//[4p] - returneaza numarul de comenzi care mai trebuie efectuate
	int GetRemainingCommands();

	//[1p] - returneaza numarul total de comenzi
	int GetCommandsCount();

	//[9p] - executa un anumit numar de comenzi - functia returneaza true daca numarul de comenzi care ar trebui executate e mai mic sau egal decat numarul de comenzi disponibile
	bool Execute(int count);

	//[1p] - returneaza coordonatele curente 
	void GetCoord(int &x,int &y);		
	
	//[2p] - duce punctul la (0, 0) si se muta cursorul inapoi la prima comanda 
	void Reset();
}