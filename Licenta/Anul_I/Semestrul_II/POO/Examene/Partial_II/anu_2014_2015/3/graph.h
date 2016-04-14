class Graph
{
private:
	//[1p] definiti membri privati pentru reprezentarea nodurilor(punctelor) si a muchiilor

public:
	//[1p] Creaza un graph gol, fara noduri, fara muchii
	Graph();

	//[1p] adauga un nod in graf
	void AddNode(int x, int y, const int& value);

	//[5p] adaugat o muchie in graf. Returneaza true daca indecsii sunt valizi, diferiti intre ei si muchia nu exista deja, false altfel
	bool AddEdge(int firstNodeIndex,int secondNodeIndex);

	//[1p] returneaza numarul de noduri
	int GetNodesCount();

	//[1p] returneaza numarul de muchii
	int GetEdgesCount();

	//[1p] returneaza nodul corespunzator pentru un index, sau NULL daca indexul nu e valid
	Node* GetNode(int index);

	//[3p] sterge o muchie
	bool DeleteEdge(int index);
	
	//[9p] returneaza true daca graful este conex, false altfel
	bool IsConex();
}