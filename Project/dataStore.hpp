#pragma once
#include "Person.hpp"
#include "Classroom.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

class DataStore
{
  public:
    DataStore() = default;
    void run();
    void printSummary();

    void listUsers() const;

void runAdminMenu(Person aPerson);

void runStudentMenu(Person aPerson);

void runTeacherMenu(Person aPerson);

std::vector<Person> getUserVector();

bool validateIdExists(std::uint32_t enteredId);
bool validateClassIdExists(std::uint32_t enteredId);
bool validateTeacherClass(std::uint32_t enteredId);

void addStudent(std::string aName, std::uint32_t aId);
void addAdmin(std::string aName, std::uint32_t aId);
void addTeacher(std::string aName, std::uint32_t aId);
void addClassroom(std::uint32_t aClassId, std::uint32_t teacherId, std::string classDescription, std::uint32_t studentCount);

private:
    std::vector<Classroom> classes{};
    std::vector<Person> users{};

    std::tuple<Role, std::uint32_t, Person> enterUserId();


};