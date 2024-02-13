#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>

using namespace std;

int main() {
    const int numStudents = 5;
    Roster classRoster;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Isaac,Meza,IsaacMeza36@gmail.com,23,30,40,50,SOFTWARE"
    };

    for (int i = 0; i < numStudents; i++) {
        classRoster.parse(studentData[i]);
    }

    cout << "class Roster: " << std::endl;
    classRoster.printAll();
    cout << std::endl;

    cout << "Locating invalid emails" << std::endl;
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << std::endl;

    cout << "Average days in course for each student is: " << std::endl;
    cout << "\n";
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }

    cout << "Scripting and Programming - Applications – C867" << std::endl;
    cout << "Language used: C++" << std::endl;
    cout << "Student ID: 010579615" << std::endl;
    cout << "Name: Isaac Meza" << std::endl;

    cout << "\n";
    cout << "Organizing roster by degree " << degreeTypeStrings[2] << std::endl;
    cout << "\n";
    classRoster.printByDegree(SOFTWARE);

    cout << std::endl;

    cout << "Removing Student A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    cout << "Removing Student A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}