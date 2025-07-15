#include "dataStore.hpp"
#include <iostream>

void DataStore::runStudentMenu(Person theStudent)
{
    bool done {false};
    while (!done)
    {
    std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++"
              << std::endl;
    std::cout << "Welcome, " << theStudent.getName() << "!" << std::endl;
    std::uint16_t studentChoice{};
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "Student Menu" << std::endl;
    std::cout << "---------------------------------------------------"
              << std::endl;
    std::cout << "1.- Register for a class" << std::endl;
    std::cout << "2.- Print my registered classes" << std::endl;
    std::cout << "3.- Print all available classes" << std::endl;
    std::cout << "4.- Exit" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"
              << std::endl;
    std::cin >> studentChoice;

    uint32_t classId{};

    switch (studentChoice)
    {
    case 1:
    {
        std::cout << "Enter id of class to register into: " << std::endl;
        std::cin >> classId;
        for (Classroom& aClass : classes)
        {
            if (classId == aClass.getId())
            {
                aClass.addStudent(theStudent);
            }
        }
        std::cout << "\nRegistration successful!" << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "Currently registered classes: " << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (Classroom aClass : classes)
        {
            for (auto student : aClass.getStudentList())
            {
                if (student.getId() == theStudent.getId())
                {
                    aClass.printClassDetails();
                }
            }
        }
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        break;
    }
    case 3:
    {
        std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "All available classes: " << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        for (Classroom aClass : classes)
        {
            aClass.printClassDetails();
        }
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        break;
    }
    case 4:
    {
        std::cout << "\n[Exiting Student Menu]" << std::endl;
        done = true;
        break;
    }
    default:
    {
        std::cout << "\nERROR: Invalid Response!" << std::endl;
        done = true;
        break;
    }
    }
}
}