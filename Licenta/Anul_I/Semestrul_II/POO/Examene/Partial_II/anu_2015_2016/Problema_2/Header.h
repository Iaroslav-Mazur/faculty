//2p - Adaugarea directivelor necesare pentru compilare.
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Grade {
	//numele materirei pentru care este nota.
	string		subject;
	//valoarea efectiva a notei.
	unsigned	value;

	bool operator < (const Grade& a) const;
};

//Lucram cu doua tipuri de studenti, la licenta (BACHELOR) sau la master.
enum StudentType { BACHELOR, MASTER };

class Student {
protected:
	string			name;
	unsigned		age;
	vector<Grade>	grades;

	//Studentii la licenta primesc 5 puncte pe punct de nota pentru materiile trecute, deci un 10 inseamna 50 de puncte.
	//Studentii la master primesc 8 puncte pe punct de note pentru materiile trecute, deci un 9 inseamna 72 de puncte.
	virtual unsigned	getPointsPerGrade() = 0;

public:
	virtual StudentType getStudentType() = 0;
	
	//Pentru calcularea punctajului se iau in considerare doar notele de trecere, adica cel putin 5.
	//1p
	unsigned			getPoints();

	//1p
	void				setName(const string& name);

	//1p
	void				setAge(unsigned age);

	//1p
	void				addGrade(const Grade& grade);	
	
	//Un set cu notele ordonate descrescator ale unui student.
	//2p
	set<Grade>			getGradeSet();
	
	//Intoarce true daca are vreo nota care nu e de trecere.
	//1p
	bool				isFailing();

	//1p
	string				getName();
};

class BachelorStudent : public Student {
protected:
	//1p
	unsigned			getPointsPerGrade();

public:
	//1p
	BachelorStudent(const string& name, unsigned age);
	BachelorStudent();

	//1p
	StudentType			getStudentType();	
};

class MasterStudent : public Student {	
protected:
	//1p
	unsigned			getPointsPerGrade();

public:
	//1p
	MasterStudent(const string& name, unsigned age);
	MasterStudent();

	//1p
	StudentType			getStudentType();
};

class DBStudents {
	vector<Student*>	students;

public:
	//Incarca studentii din fisier.
	//4p
	void														loadFromFile(string fileName);

	//Intoarce o pereche cu ierarhiile de studenti de la licenta si de la master.
	//Ierarhiile contin studentii care au doar note de trecere ordonati descrescator dupa punctaj.
	//3p
	pair<vector<BachelorStudent*>, vector<MasterStudent*> >		orderStudents();

	//Eleimina tot studentii care au cel putin o nota care nu e de trecere.
	//2p
	void														removeFailingStudents();
};
