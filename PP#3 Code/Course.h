// Course.h
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include "Student.h"

// Declares Course class
class Course {
private: // Private data members to store course name and registered student IDs
    std::string courseName;
    std::vector<int> studentIDs;
    
public:
    // Constructor to intialize a course object
    Course(std::string name);
   
    // Getter to access the course name
    std::string GetName() const;
    
    // Checks to see if the student ID is registered inside the course
    bool Registered(int studentID) const;
    
    // Prints the roster of students based on the print order
    void PrintRoster(int printOrder, std::vector<Student> students) const;
    
    // Adds a student ID to the course if not already registered
    void AddStudent(int studentID);
};

#endif