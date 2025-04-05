// Student.cpp
#include "Student.h"

// Constructor definition for the initialization of a Student object
Student::Student(std::string frstName, std::string lstName, int id, double gpa)
    : firstName(frstName), lastName(lstName), studentID(id), GPA(gpa) {}

// Returns the first name of the student
std::string Student::GetFirstName() const {
    return firstName;
}

// Returns the last name of the student
std::string Student::GetLastName() const {
    return lastName;
}

// Returns the student ID
int Student::GetID() const {
    return studentID;
}

// Returns the student's GPA
double Student::GetGPA() const {
    return GPA;
}