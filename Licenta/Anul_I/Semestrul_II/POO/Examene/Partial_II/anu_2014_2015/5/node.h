class Node
{
private:
	int Value;
	// [1p] definiti si copii acestui Nod
public:
	// [1p] creaza un nod nou si ii seteaza valoarea
	Node(const int &value);

	// [2p] adauga un nod nou la ca si copil pentru nodul curent
	Node* AddNode(const Node& nod);

	// [1p] returneaza numarul de copii a nodului curent
	int GetCount();

	// [2p] returneaza un copil al nodului curent sau NULL daca se trimite un index invalid sau nodul curent nu are copii
	Node* Get(int index);

	// [1p] seteaza valoarea unui nod
	void SetValue(const int& value);
	
};