#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "average.h"
#include "student.h"

void add_student (std::vector<student*>* students, std::istringstream& iss) 
{
  // Your code here. 
  // Implement a function to add one student and their grades from the input stream to the vector

    std::vector<int>grades;
    std::vector<std::string> tokens;

    std::string token;

    while (getline(iss, token, ' '))
    {
        tokens.push_back(token);
    }

    student* currentStudent = new student;
    currentStudent->name = tokens[0];
    currentStudent->id = stoi(tokens[1]);

    for (auto i = 2; i < tokens.size(); i++)
    {
        if (!tokens[i].empty())
        {
            int x = int(stod(tokens[i]));
            currentStudent->grades.push_back(x);
        }
    }

    students->push_back(currentStudent);
}

std::vector<student*> load_classroom() 
{
  std::string line;
  std::vector <student*> classroom;
  // Your code here. Init a new classroom
  while (getline(std::cin, line))
  {
      if (!line.empty())
      {
          std::istringstream stream(line);
          // Your code here. add students to the classroom
          add_student(&classroom, stream);

      }
      line.clear();
  }
  // Your code here. Return your classroom
  return classroom;
}

std::ostream& operator<< (std::ostream& os, const std::vector<student*>& rhs) 
{
  // Your code here. Implement a function to print all students
    for (auto i : rhs)
    {
        os << i;
    }

    return os;
}

std::ostream& operator<< (std::ostream& os, const student* rhs) 
{
  // Your code here. Implement a function to print one student

    return os << "Name:\t" << rhs->name << "\tId:\t" << rhs->id
        << "\tAvg:\t" << average(rhs->grades) << '\n';
}


