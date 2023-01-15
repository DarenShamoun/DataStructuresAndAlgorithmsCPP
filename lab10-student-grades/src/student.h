#pragma once

#include <iosfwd>
#include <string>
#include <vector>

struct student 
{
    std::string name;
    unsigned id;
    std::vector<int>grades; 
};

// Add a new student from a input string stream to the list of students
void add_student(std::vector<student*>* students, std::istringstream& iss);

// load an entire classroom of students and return it
std::vector<student*> load_classroom(); 

// write an entire classroom to an output stream
std::ostream& operator<< (std::ostream& os, const std::vector<student*>& rhs); 

// write an one student to an output stream
std::ostream& operator<< (std::ostream& os, const student* rhs);
