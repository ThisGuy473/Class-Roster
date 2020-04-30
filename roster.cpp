#pragma once
#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//https://www.tutorialspoint.com/cplusplus/cpp_array_of_pointers.htm
    
Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->students = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;//-1 means empty
    this->students = new Student*[capacity];
}

Student* Roster::getStudentAt(int row)
{
    return students[row];
}
   
void Roster::parseThenAdd(string row)
{

            if (lastIndex < capacity)
            {   
                lastIndex++;
                // get the studentId by splitting the string from position 0 till the 1st comma
                size_t idPosEnd = row.find(",");
                string sstudentId = row.substr(0, idPosEnd);

                // https://www.cplusplus.com/reference/string/string/find/
                size_t firstNamePosStart = row.find(",", idPosEnd) + 1;
                size_t firstNamePosEnd = row.find(",", firstNamePosStart);
                string sfirstname = row.substr(firstNamePosStart, firstNamePosEnd - idPosEnd - 1);

                size_t lastNamePosStart = row.find(",", firstNamePosEnd) + 1;
                size_t lastNamePosEnd = row.find(",", lastNamePosStart);
                string slastname = row.substr(lastNamePosStart, lastNamePosEnd - firstNamePosEnd - 1);

                size_t emailAddressPosStart = row.find(",", lastNamePosEnd) + 1;
                size_t emailAddressNamePosEnd = row.find(",", emailAddressPosStart);
                string semail = row.substr(emailAddressPosStart, emailAddressNamePosEnd - lastNamePosEnd - 1);

                size_t agePosStart = row.find(",", emailAddressNamePosEnd) + 1;
                size_t agePosEnd = row.find(",", agePosStart);
                int sage = stoi(row.substr(agePosStart, agePosEnd - emailAddressNamePosEnd - 1));

                size_t daysInCourse1PosStart = row.find(",", agePosEnd) + 1;
                size_t daysInCourse1PosEnd = row.find(",", daysInCourse1PosStart);
                int sdaysInCourse1 = stoi(row.substr(daysInCourse1PosStart, daysInCourse1PosEnd - agePosEnd - 1));

                size_t daysInCourse2PosStart = row.find(",", daysInCourse1PosEnd) + 1;
                size_t daysInCourse2PosEnd = row.find(",", daysInCourse2PosStart);
                int sdaysInCourse2 = stoi(row.substr(daysInCourse2PosStart, daysInCourse2PosEnd - daysInCourse1PosEnd - 1));

                size_t daysInCourse3PosStart = row.find(",", daysInCourse2PosEnd) + 1;
                size_t daysInCourse3PosEnd = row.find(",", daysInCourse3PosStart);
                int sdaysInCourse3 = stoi(row.substr(daysInCourse3PosStart, daysInCourse3PosEnd - daysInCourse2PosEnd - 1));

                size_t DegreePosStart = row.find(",", daysInCourse3PosEnd) + 1;
                size_t DegreePosEnd = row.find(",", DegreePosStart);
                string sprogram = row.substr(DegreePosStart, DegreePosEnd - daysInCourse3PosEnd - 1);
                DegreeProgram programTypeStrings;

                if (sprogram == "NETWORKS") {
                    degreeProgram = NETWORKS;
                }
                else if (sprogram == "SECURITY") {
                    degreeProgram = SECURITY;
                }
                else if (sprogram == "SOFTWARE") {
                    degreeProgram = SOFTWARE;
                }

                add(sstudentId, sfirstname, slastname, semail, sage, sdaysInCourse1, sdaysInCourse2, sdaysInCourse3, degreeProgram);
            }
            else
            {
                cerr << "ERROR! LIST HAS EXEEDED CAPACITY!\n EXITING NOW!";
                exit(-1);
            }
            
}

//This method creates the Student and adds the Student to the Roster - the parsed values are passed in
void Roster::add(string sstudentId, string sfirstname, string slastname, string semail, int sage, int sdaysInCourse1, int sdaysInCourse2, int sdaysInCourse3, DegreeProgram degreeProgram)
{
    //Make an array to get the daysInCourse into the constructor
    int daysInCourse[Student::daysInCourseArraySize];//This is in the public Student class
    daysInCourse[0] = sdaysInCourse1;
    daysInCourse[1] = sdaysInCourse2;
    daysInCourse[2] = sdaysInCourse3;
    students[lastIndex] = new Student(sstudentId, sfirstname, slastname, semail, sage, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
}

bool Roster::remove(string studentID)
{
     //removes students from the roster by student ID
     bool found = false;
     for (int i = 0; i <= lastIndex; i++)
     {
         if (this->students[i]->getStudentId() == studentID) //Student found
         {
             found = true;
             cout << "Student#: '" << studentID << "' REMOVED!\n" << endl;
             //delete student
             delete this->students[i];
             this->students[i] = this->students[lastIndex];
             lastIndex--; 
         }
     }
     if(found == false)
     {
         cout << "Student Not Found!!\n\n";
     }
    return found;
}

//Prints all Students listed in Roster
void Roster::print_All()
{
    // prints a complete tab-separated list of student data in the provided format:
    // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
    cout << "Displaying Students:\n";
    //This is runtime polmorphism!!!
    for (int i = 0; i <= this->lastIndex; i++) 
    {
        cout << '\n';
        (this->students)[i]->printStudent();
    }
    
}

void Roster::printAverageDaysInCourse(string studentId)
{
    //correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
    bool found = false;
    for (int i=0; i <= lastIndex; i++)
    {
        if (this->students[i]->getStudentId() == studentId) //Student found
        {
            found = true;
            int* p = students[i]->getDaysInCourse();
            cout << '\n';
            cout << "Average days in course for student#: " << studentId << ": " << (p[0] + p[1] + p[2]) / 3 << "\n";
        }
    }
    if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()//Finds all invalid email addresses and outputs which and why they are invalid
{
    for (int i = 0; i <= this->lastIndex; i++) 
    {
        cout << '\n';
        string emailString = students[i]->getEmail(); 
        size_t atsign = emailString.find('@');//searches string for an '@' sign
        if (atsign == string::npos)
        {
            cout << "Student ID # '" << students[i]->getStudentId() << "' -INVALID EMAIL! " << "'" << emailString << "'" << " Missing '@' symbol\n";
            
        }

        size_t period = emailString.find('.');//searches string for a period
        if (period == string::npos)
        {
            cout << "Student ID # '" << students[i]->getStudentId() << "' -INVALID EMAIL! " << "'" << emailString << "'" << " Missing '.' symbol\n";
            
        }
        
        for (size_t j = 0; j < emailString.size(); ++j)
        {
            if (isspace(emailString[j]) >= 2)
            {
                cout << "Student ID # '" << students[i]->getStudentId() << "' -INVALID EMAIL! " << "'" << emailString << "'" << " Invalid [space] in email.\n";
            }    
            
            
        }

    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)//This will print all Students in the desired degree program from the roster
{
    string program = programTypeStrings[degreeProgram]; 
    cout << endl;
    cout << "PRINTING ALL " << program << " STUDENTS:\n" << endl;
    for (int i = 0; i <= this->lastIndex; i++) 
    {
        if((this->students)[i]->getProgram() == degreeProgram)
        {
            students[i]->printStudent();
            cout << endl;
        }
        
    }
    
}



   