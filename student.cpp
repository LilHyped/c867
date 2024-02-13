#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using std::string;
using std::cout;
using namespace std;

class student
{
public:
    const static int DaysInCourseArraySize = 3;

private:
    string StudentID;
    string FirstName;
    string LastName;
    string Email;
    int Age;
    double DaysInCourse[DaysInCourseArraySize];
    Degree degreeType;

public:
    student() { //constructor
    }
    student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degreeType) { //constructor
    }
    // accessors-getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    double* getDaysInCourse();
    Degree getdegreeType();

    // mutator-setters
    void setStudentID(string StudentID);
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setEmail(string Email);
    void setAge(int Age);
    void setDaysInCourse(double DaysInCourse[]);
    void setdegreeType(Degree degreeType);

	void print();
    static void printHeader();
    ~student(); // destructor
};

   void student::printHeader() {
    cout << "Student ID\tFirst Name\tLast Name\tEmail\tAge\tDays in Course 1\tDays in Course 2\tDays in Course 3\tDegree" << std::endl;
}