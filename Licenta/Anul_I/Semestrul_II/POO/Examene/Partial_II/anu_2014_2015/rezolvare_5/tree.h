class Tree
{
private:
	Node *Root;
public:
	//[1p] obiectul Root este setat la NULL
	Tree();		
	
	//[2p] creaza nodul parinte si ii adauga o valoare. Daca nodul root exista nu il creaza ci il returneaza pe cel existent
	Node* CreateRoot(const int &value);	

	//[1p] returneaza nodul parinte
	Node* GetRoot(); 

	//[6p] afiseaza toate nodurile in format
	void Show();

	//[5p] Returneaza un nod din arbore (daca exista) care are o anumita valoarea
	Node* FindNode(const int& valueToFind);
};