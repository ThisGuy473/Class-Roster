#include "student.h"
#include<iomanip>
using std::cout;
using std::left;
using std::setw;

//Mutators
void Student::setStudentId(string s) 
{
	studentId = s;
}
void Student::setFirstname(string f) 
{
	firstname = f;
}
void Student::setLastname(string l) 
{
	lastname = l;
}
void Student::setEmail(string e) 
{
	email = e;
}
void Student::setAge(int a) 
{
	age = a;
}
void Student::setDaysInCourse(int d[]) 
{
	daysInCourse[0] = d[0];
	daysInCourse[1] = d[1];
	daysInCourse[2] = d[2];
}
void Student::setProgram(DegreeProgram p) 
{
	program = p;
}

//Accessors
string Student::getStudentId() const 
{
	return studentId;
}

string Student::getFirstname() const 
{
	return firstname;
}
string Student::getLastname() const 
{
	return lastname;
}
string Student::getEmail() const 
{
	return email;
}
int Student::getAge() const 
{
	return age;
}
// why const needed: https://stackoverflow.com/a/3141107/4151489
int * Student::getDaysInCourse()
{
	return daysInCourse;
}
DegreeProgram Student::getProgram() const 
{
	return program;
};

void Student::printStudent()
{
	cout << this->getStudentId() << "\t";
    cout << this->getFirstname() << "\t";
	cout << this->getLastname() << "\t";
	cout << this->getEmail() << "\t";
	cout << this->getAge() << "\t";
	cout << "{" << this->getDaysInCourse()[0] << ", " << this->getDaysInCourse()[1] << ", " << this->getDaysInCourse()[2] << "}" << "\t";
	cout << programTypeStrings[this->getProgram()] << endl;
}