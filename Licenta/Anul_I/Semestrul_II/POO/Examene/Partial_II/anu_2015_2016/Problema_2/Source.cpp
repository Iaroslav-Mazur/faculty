//Implementare
#include "Header.h"
#include <fstream>



// Student
void Student::setName(const string& name){
    this->name = name;
}

void Student::setAge(unsigned age){
    this->age = age;
}

void Student::addGrade(const Grade& grade){
    this->grades.push_back(grade);
}

string Student::getName(){
    return this->name;
}

set<Grade> Student::getGradeSet(){
    set<Grade> s;
    vector<Grade>::iterator it;
    for(it = this->grades.begin(); it != this->grades.end(); it++){
        Grade g = (Grade)(*it);
        s.insert(g);
    }
    
    return s;
}

bool Student::isFailing(){
    vector<Grade>::iterator it;
    unsigned total= 0;
    for(it = this->grades.begin(); it != this->grades.end(); it++){
        Grade g = (Grade)(*it);
        if( g.value < 5 ){
            return true;
        }
    }

    return false;
}

unsigned Student::getPoints(){
    vector<Grade>::iterator it;
    unsigned total= 0;
    for(it = this->grades.begin(); it != this->grades.end(); it++){
        Grade g = (Grade)(*it);
        if( g.value >= 5 ){
            total += g.value * this->getPointsPerGrade();
        }
    }

    return total;
}




// Licenta
unsigned BachelorStudent::getPointsPerGrade(){
    return 7; 
}
BachelorStudent::BachelorStudent(const string& name, unsigned age){
    this->name = name; 
    this->age = age;
}

BachelorStudent::BachelorStudent(){
    this->name = string("Jon Doe");
    this->age = 0;
}

StudentType BachelorStudent::getStudentType(){
    return BACHELOR;
}


// Master
unsigned MasterStudent::getPointsPerGrade(){
    return 5; 
}

MasterStudent::MasterStudent(const string& name, unsigned age){
    this->name = name; 
    this->age = age;
}

MasterStudent::MasterStudent(){
    this->name = string("Jon Doe");
    this->age = 0;
}

StudentType MasterStudent::getStudentType(){
    return MASTER;
}


// DB

void DBStudents::loadFromFile(string fileName){
    int a;
}

pair<vector<BachelorStudent*>, vector<MasterStudent*> > DBStudents::orderStudents(){
    pair<vector<BachelorStudent*>, vector<MasterStudent*> > s;
    
    return s;
}

void DBStudents::removeFailingStudents(){
    vector<Student*>::iterator it;
    for(it = this->students.begin(); it != this->students.end(); it++){
        Student *s = (Student*)(*it);
        if(s->isFailing()){
            this->students.erase(it);
        }
    }
}
