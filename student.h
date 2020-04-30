#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

//This is the Student class.
class Student
{
	public:
		const static int daysInCourseArraySize = 3;

		void setStudentId(string s); 		// Mutator
		void setFirstname(string f); 	// Mutator
		void setLastname(string l); 	// Mutator
		void setEmail(string e); 		// Mutator
		void setAge(int a); 			// Mutator
		// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
		void setDaysInCourse(int d[]); 		// Mutator
		void setProgram(DegreeProgram p); 		// Mutator

		void printStudent();		//Student printer

		string  getStudentId() const;        		// Accessor
		string  getFirstname() const;       	 // Accessor
		string  getLastname() const;        	// Accessor
		string  getEmail() const;       		 // Accessor
		int getAge() const;        				// Accessor
		// https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
		int * getDaysInCourse();        		// Accessor
		DegreeProgram getProgram() const;        // Accessor	
		
		Student() //empty constructor
		{
			
		}; 
		
		//constructor
		Student(string astudentId, string afirstname, string alastname, string aemail, int aage, int courseDays1, int courseDays2, int courseDays3, DegreeProgram aprogram)
		{
			studentId = astudentId;
			firstname = afirstname;
			lastname = alastname;
			email = aemail;
			age = aage;
			daysInCourse[0] = courseDays1;
			daysInCourse[1] = courseDays2;
			daysInCourse[2] = courseDays3;
			program = aprogram;
		}
	private:
		//the variables for student class
		string studentId;
		string firstname;
		string lastname;
		string email;
		int age;
		int daysInCourse[daysInCourseArraySize];
		DegreeProgram program;

		
};


