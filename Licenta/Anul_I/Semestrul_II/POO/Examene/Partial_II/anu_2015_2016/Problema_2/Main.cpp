#include "Header.h"
#include <iostream>

int main() {
	DBStudents db;
	db.loadFromFile("students.txt");
	db.removeFailingStudents();
	pair<vector<BachelorStudent*>, vector<MasterStudent*> > p = db.orderStudents();

	cout << "LICENTA:\n";
	for (unsigned i = 0; i < p.first.size(); ++i) {
		cout << p.first[i]->getName() << "\n";
	}

	cout << "MASTER:\n";
	for (unsigned i = 0; i < p.second.size(); ++i) {
		cout << p.second[i]->getName() << "\n";
	}

	cout << "\n\n";

	set<Grade> S = p.first[0]->getGradeSet();
	set<Grade>::iterator it = S.begin();
	for (; it != S.end(); ++it) {
		cout << it->subject << " " << it->value;
		cout << "\n";
	}	

	return 0;
}
