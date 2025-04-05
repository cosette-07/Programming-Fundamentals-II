// Course.cpp
#include "Course.h"
#include <iostream>
#include <algorithm>

// Two functions defined to help with sorting
bool CompareByLastName(Student a, Student b) {
    return a.GetLastName() < b.GetLastName();
}
    
bool CompareByID(Student a, Student b) {
    return a.GetID() < b.GetID();
}

// Constructor definition for the intialization of a course name
Course::Course(std::string name) : courseName(name) {}

// Returns the name of the course
std::string Course::GetName() const {
    return courseName;
}

// Checks if a student ID is in the registered list
bool Course::Registered(int studentID) const {
   for (int id : studentIDs) {
       if (id == studentID) {
           return true;
       }
   }
   return false;
}

// Adds not present students to the list
void Course::AddStudent (int StudentID) {
    // Checks if the student ID is already in the list
    bool found = false;
    for (int i = 0; i < studentIDs.size(); i++) {
        if (studentIDs[i] == StudentID) {
            found = true;
            break; // Exits the loop early because it found the ID
        }
    }
    // If the student ID was not found, it gets added to the list
    if (!found) {
        studentIDs.insert(studentIDs.end(), StudentID);
    }
}

// Prints the roster of students enrolled in the course
void Course::PrintRoster(int printOrder, std::vector<Student> students) const {
    std::vector<Student> enrolledStudents;
    
    // Loops through each of the students in the list
    for (int i= 0; i < students.size(); i++) {
        // Gets the student's ID
        int id = students[i].GetID();
        
        // Check if this student is registered in the course
        if (Registered(id)) {
            // Adds the student to the end of the enrolledStudents vector
            enrolledStudents.insert(enrolledStudents.end(), students[i]);
        }
    }
    
    // Sorts students alphabetically by last name if printOrder == 0
    if (printOrder == 0) {
        std::sort(enrolledStudents.begin(), enrolledStudents.end(), CompareByLastName);
    }
    
    // Otherwise it sorts by student ID
    else {
        std::sort(enrolledStudents.begin(), enrolledStudents.end(), CompareByID);
    }

    // Loops through each student in the enrolledStudents list
    for (int i = 0; i < enrolledStudents.size(); i++) {
    // Gets the current student
    Student student = enrolledStudents[i];

    // Prints the student's details
    std::cout << "StudentID: " << student.GetID()
              << ", " << student.GetLastName()
              << ", " << student.GetFirstName() << std::endl;
    }
}
