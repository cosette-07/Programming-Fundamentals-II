// Student.h
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

// Declares Student Class
class Student {
private: // Private data members to store first name, last name, student ID, and GPA
    std::string firstName;
    std::string lastName;
    int studentID;
    double GPA;

public: 
    // Constructor to initialize a student object
    Student(std::string frstName, std::string lstName, int id, double gpa);
   
    // Getters to access the private data members
    std::string GetFirstName() const;
    std::string GetLastName() const;
    int GetID() const;
    double GetGPA() const;
};

#endif 