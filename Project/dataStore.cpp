#include "dataStore.hpp"
#include "Classroom.hpp"
#include "mainMenu.hpp"
#include "Person.hpp"
#include <iostream>
#include <tuple>
#include <vector>

void DataStore::run()
{
    Menu1 theMainMenu{};

    Person defaultAdmin{Role::Admin, std::string{"Default Admin"},
                        std::uint32_t{0}};
    users.push_back(defaultAdmin);

    bool myExit = false;

    while (!myExit)
    {
        auto myMenuOption = theMainMenu.getMenuOption();

        switch (myMenuOption)
        {
        case (Menu1::Options::ENTER_USER_ID):
        {
            auto [userType, userId, thePerson] = enterUserId();
            if (userType == Role::Admin)
            {
                runAdminMenu(thePerson);
            }
            else if (userType == Role::Student)
            {
                runStudentMenu(thePerson);
            }
            else if (userType == Role::Teacher)
            {
                runTeacherMenu(thePerson);
            }
            else
            {
                std::cout << "\nERROR: User was not found in database!"
                          << std::endl;
            }
        }
        break;
        case (Menu1::Options::LIST_USERS):
        {
            std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++"
                      << std::endl;
            std::cout << "List of Users: " << std::endl;
            std::cout << "---------------------------------------------------"
                      << std::endl;
            listUsers();
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"
                      << std::endl;
        }
        break;
        case (Menu1::Options::EXIT):
        {
            std::cout << "\nThanks for using this program!" << std::endl;
            myExit = true;
        }
        break;
        default:
            throw std::runtime_error("Unhandled option");
            break;
        }
    }
    return;
}

std::tuple<Role, std::uint32_t, Person> DataStore::enterUserId()
{
    Person someDude{Role::Unknown, "", 1};
    std::tuple<Role, std::uint32_t, Person> myTuple = {Role::Unknown, 1,
                                                       someDude};
    std::get<1>(myTuple) =
        readInput<std::uint32_t>("Please enter your user ID:");

    for (Person person : users)
    {
        if (std::get<1>(myTuple) == person.getId())
        {
            std::get<0>(myTuple) = person.getRole();
            std::get<2>(myTuple) = person;
        }
    }

    return myTuple;
}

void DataStore::listUsers() const
{
    for (Person Person : users)
    {
        Person.printSummary();
    }
}

void DataStore::printSummary() {}

void DataStore::addStudent(std::string aName, std::uint32_t aId)
{
    Person newStudent{Role::Student, aName, aId};
    users.push_back(newStudent);
}

void DataStore::addAdmin(std::string aName, std::uint32_t aId) // only admin
{
    Person newAdmin{Role::Admin, aName, aId};
    users.push_back(newAdmin);
}

void DataStore::addTeacher(std::string aName, std::uint32_t aId) // only admin
{
    Person newTeacher{Role::Teacher, aName, aId};
    users.push_back(newTeacher);
}

void DataStore::addClassroom(std::uint32_t aClassId, std::uint32_t teacherId,
                             std::string classDescription,
                             std::uint32_t studentCount)
{
    Classroom newClass{aClassId, teacherId, classDescription, studentCount};
    classes.push_back(newClass);
}

bool DataStore::validateIdExists(std::uint32_t enteredId)
{
    for (auto person : users)
    {
        if (person.getId() == enteredId)
        {
            return false;
        }
    }

    for (auto currentClass : classes)
    {
        if (currentClass.getClassId() == enteredId)
        {
            return false;
        }
    }
    return true;
}

bool DataStore::validateTeacherClass(std::uint32_t enteredId)
{
    for (auto person : users)
    {
        if (person.getId() == enteredId && person.getRole() == Role::Teacher)
        {
            return true;
        }
    }
    return false;
}

bool DataStore::validateClassIdExists(std::uint32_t enteredId)
{
    for (auto currentClass : classes)
    {
        if (currentClass.getClassId() == enteredId)
        {
            return true;
        }
    }
    return false;
}