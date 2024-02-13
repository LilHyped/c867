#pragma once
#include "roster.h"
#include "student.h"
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include "degree.h"
#include "student.cpp"
using namespace std;

Roster::Roster()
{
}

void Roster::parse(string studentData)
{
	Degree degreeType = Degree::SECURITY;
    if (studentData.back() == 'K') 
        degreeType = Degree::NETWORK;
    else if (studentData.back() == 'E') 
        degreeType = Degree::SOFTWARE;

	int rhs = studentData.find(",");
	string StudentID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FirstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EmailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int Age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DaysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int DaysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int DaysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));


	add(StudentID, FirstName, LastName, EmailAddress, Age, DaysInCourse1, DaysInCourse2, DaysInCourse3, degreeType);
}


void Roster::add(string StudentID, string FirstName, string LastName, string Email, int Age, int DaysInCourse1, int DaysInCourse2, int DaysInCourse3, Degree degreeType) 
{
    int DaysInCourse[3] = { DaysInCourse1, DaysInCourse2, DaysInCourse3 };
classRosterArray[++rosterIndex] = new Student(StudentID, FirstName, LastName, Email, Age, DaysInCourse[0], DaysInCourse[1], DaysInCourse[2], degreeType);
}


void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::rosterIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmail(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
		cout << degreeTypeStrings[classRosterArray[i]->getDegree()] << std::endl;
	}
}


void Roster::printAverageDaysInCourse(string StudentID)
{
	for (int i = 0; i <= Roster::rosterIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			cout << " Student ID: ";
			cout << StudentID;
			cout << ",";
			cout << " averages ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << " days in a course.";


		}

	}cout << endl;
}



void Roster::printInvalidEmails()
{
	bool any = false;

	for (int i = 0; i <= Roster::rosterIndex; i++)
	{
		string EmailAddress = (classRosterArray[i]->getEmail());
		if (EmailAddress.find("@") == string::npos || (EmailAddress.find('.') == string::npos) || (EmailAddress.find(' ') != string::npos))
		{
			any = true;
			cout << EmailAddress << ": " << classRosterArray[i]->getEmail() << std::endl;


		}
	}
	if (!any) cout << "NONE" << std::endl;


}


void Roster::printByDegree(Degree degreeType)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::rosterIndex; i++) {
		if (Roster::classRosterArray[i]->getDegree() == degreeType) classRosterArray[i]->print();
	}
	cout << std::endl;


}


void Roster::remove(string StudentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::rosterIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == StudentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::rosterIndex--;



		}

	}
	if (success)
	{
		cout << StudentID << " removed from roster." << endl << std::endl;
		this->printAll();
	}

	else cout << StudentID << " studentID not found" << std::endl << std::endl;

}

Roster::~Roster()
{
	cout << "Destructor Called" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}

};
