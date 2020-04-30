#pragma once
#include <iostream>
#include <string>
#include "student.cpp"
#include "roster.cpp"
#include <ctype.h>



//This the Roster class that stores all the Student Data
class Roster
{
public:
        DegreeProgram degreeProgram;
        Student* getStudentAt(int index); 
        void parseThenAdd(string studentData);
        void add(string studentID, string firstName, string lastName, string emailAddress, int sage, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);
        bool remove(string studentID);
        void print_All();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        int issspace(int c);

        Roster();//empty constructor
        Roster(int capacity); //sets max size of roster 
        
private:
        const int classSize = 5;
        Student** students; //students is an array of pointers to students
        int lastIndex;//index of last student in roster-records how many students in the roster there are.
        int capacity;//max size of the roster
};