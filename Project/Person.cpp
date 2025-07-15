#include "Person.hpp"
#include <iostream>

void Person::printSummary()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Id: " << Id << " (" << stringRole << ")" << std::endl;
}

uint32_t Person::getId()
{
    return Id;
}

Role Person::getRole()
{
    return theRole;
}

std::string Person::getName()
{
    return name;
}
