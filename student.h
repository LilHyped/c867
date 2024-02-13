#pragma once
#include <string>
#include "degree.h"

class Student {
public:
    static const int DaysInCourseArraySize = 3;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    double daysInCourse[DaysInCourseArraySize];
    Degree degreeType;

public:
    Student();  // constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, double daysInCourse[], Degree degreeType);  // constructor

    // getters
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getAge();
    double* getDaysInCourse();
    Degree getDegree();

    // setters
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(double daysInCourse[]);
    void setDegree(Degree degreeType);

    static void printHeader();

    void print();

    ~Student();  // destructor
};