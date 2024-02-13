#pragma once
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
public:
    Roster(); 
    const static int numStudents = 5;
    Student* classRosterArray[numStudents];
    int rosterIndex;
	void parse(std::string row);
    void add(std::string StudentID, std::string FirstName, std::string LastName, std::string Email, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, Degree degreeType);
    void printAll();
    void printByDegree(Degree degreeType);
    void printInvalidEmails();
    void printAverageDaysInCourse(std::string studentID);
    void remove(std::string studentID);
};