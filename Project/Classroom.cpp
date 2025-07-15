#include "Classroom.hpp"
#include "mainMenu.hpp"
#include <iostream>

uint32_t Classroom::getId()
{
    return ClassId;
}

void Classroom::addStudent(Person theStudent)
{
    Classroom::listOfStudents.push_back(theStudent);
}


void Classroom::printClassDetails() const
{
    std::uint32_t cnt{};
    for (Person aPerson: listOfStudents)
    {
        cnt++;
    }
    std::cout << "Class Name: " << Classroom::classDesc << std::endl;
    std::cout << "Class Id: " << Classroom::ClassId << std::endl;
    std::cout << "Teacher Id: " << Classroom::teacherId << std::endl;
    std::cout << "Student Count: " << cnt << " out of " << Classroom::studentCnt << " spots taken" << std::endl;


}

std::vector<Person> Classroom::getStudentList()
{
    return listOfStudents;
}

std::uint32_t Classroom::getTeacherId()
{
    return teacherId;
}

std::uint32_t Classroom::getClassId()
{
    return ClassId;
}
