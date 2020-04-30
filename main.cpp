#include "roster.cpp"
#include "pch.h"
#include <iostream>
#include <string>

//using namespace std;

   
int main()
{
   cout << "Scripting and Programming - Applications – C867" << endl;
   cout << "C++" << endl;
   cout << "WGUID#:001219603" << endl;
   cout << "Jeffrey Day\n" << endl;

   
   string studentData[] = 
   {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Jeffrey,Day,jeffday473@gmail.com,26,30,12,16,SOFTWARE"
   };
   
   const int numStudents = sizeof(studentData)/sizeof(studentData[0]);
   

   Roster * ros = new Roster(numStudents);
   cout << "Parsing data and adding students:\t" << "FINISHED." << endl;
   for (int i = 0; i < numStudents; i++)
   {
      ros->parseThenAdd(studentData[i]);//parse each line, then turn into a Student class, and add them to the roster
   }
   
   ros->print_All();//Display every student in the roster
   
   ros->printInvalidEmails();//Display all invalid emails
   
   for (int i = 0; i < numStudents; i++)
   {
      ros->printAverageDaysInCourse(ros->getStudentAt(i)->getStudentId());
   }
   
   ros->printByDegreeProgram(SOFTWARE);//Print all students of the given Degree Program
   
   if (ros->remove("A3"))
   {
      ros->print_All();
      cout << endl;
   }
   //else cout << "Student not found!\n\n";
   //prints an error message indicating that the student was not found.

   if (ros->remove("A3"))
   {
      ros->print_All();
      cout << endl;
   }
   //else cout << "Student not found!\n\n";
   
  return 0;
}

