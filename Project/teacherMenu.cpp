#include "dataStore.hpp"
#include <iostream>

void DataStore::runTeacherMenu(Person theTeacher)
{
    bool done{false};
    while (!done)
    {
        std::uint16_t teacherChoice{};
        std::uint32_t classIdEntered{};
        std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++"
                  << std::endl;
        std::cout << "Welcome, " << theTeacher.getName() << "!" << std::endl;
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << "Teacher Menu" << std::endl;
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << "1.- List classes assigned" << std::endl;
        std::cout << "2.- See assigned class roster" << std::endl;
        std::cout << "3.- Exit" << std::endl;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"
                  << std::endl;
        std::cin >> teacherChoice;

        switch (teacherChoice)
        {
        case 1:
        {
            std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "Classes you are assigned to: " << std::endl;
            std::cout << "---------------------------------------------------" << std::endl;
            for (Classroom aClass : classes)
            {
                if (aClass.getTeacherId() == theTeacher.getId())
                {
                    aClass.printClassDetails();
                }
            }
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Enter class id: " << std::endl;
            std::cin >> classIdEntered;
            if(validateClassIdExists(classIdEntered))
            {
            for (Classroom aClass : classes)
            {
                if (aClass.getId() == classIdEntered)
                {
                    std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "Student roster: " << std::endl;
                    std::cout << "---------------------------------------------------" << std::endl;
                    for (auto student : aClass.getStudentList())
                    {
                        std::cout << student.getName() << std::endl;
                    }
                    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                }
            }
            }
            else
            {
                std::cout << "\nERROR: Class does not exist!" << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << "\n[Exiting Teacher Menu]" << std::endl;
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