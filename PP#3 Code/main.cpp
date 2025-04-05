// main.cpp
#include <iostream>
#include "Student.h"
#include "Course.h"
#include <vector>

int main() {
    // Creates some students
    Student s1("Isaiah", "Williams", 128, 2.0);
    Student s2("Sophia", "Smith", 147, 1.2);
    Student s3("Mia", "Green", 101, 3.3);
    Student s4("Steven", "Schneider", 197, 4.0);
    Student s5("Mark", "Twain", 132, 2.5);

    // Stores all students in a vector
    std::vector<Student> allStudents = {s1, s2, s3, s4, s5};

    // Creates two different courses
    Course courseA("History 1301");
    Course courseB("Composition 1");

    // Registers some of the students in Course A
    courseA.AddStudent(101); // Mia Green
    courseA.AddStudent(132); // Mark Twain
    courseA.AddStudent(128); // Isaiah Williams

    // Registers some of the students in Course B
    courseB.AddStudent(197); // Steven Schneider
    courseB.AddStudent(147); // Sophia Smith

    // Prints course A roster sorted alphabetically by last name
    std::cout << "Roster for " << courseA.GetName() << " (sorted by last name):" << std::endl;
    courseA.PrintRoster(0, allStudents); // 0 = sort by last name

    std::cout << std::endl;

    // Prints course B roster sorted by student ID
    std::cout << "Roster for " << courseB.GetName() << " (sorted by student ID):" << std::endl;
    courseB.PrintRoster(1, allStudents); // 1 = sort by ID

    return 0;
}
