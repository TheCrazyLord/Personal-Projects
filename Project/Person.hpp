#pragma once
#include <cstdint>
#include <string>

enum class Role
{
    Student = 1,
    Admin,
    Teacher,
    Unknown
};

class Person
{
  public:
  std::string stringRole {""};

    Person(Role aRole, std::string aName, std::uint32_t aId) : name(aName), Id(aId), theRole(aRole)
    {
        if (aRole == Role::Admin)
        {
            stringRole = "Admin";
        }
        else if (aRole == Role::Student)
        {
            stringRole = "Student";
        }
        else
        {
            stringRole = "Teacher";
        }
    }

    uint32_t getId();
    Role getRole();
    std::string getName();
    void printSummary();

    private:
    std::string name {""};
    std::uint32_t Id {};
    Role theRole {};

};
