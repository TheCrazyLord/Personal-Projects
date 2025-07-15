#include "dataStore.hpp"
#include <iostream>
#include <limits>

void DataStore::runAdminMenu(Person theAdmin)
{
    bool done{false};
    while (!done)
    {
        std::uint16_t adminChoice{};
        std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++"
                  << std::endl;
        std::cout << "Welcome, " << theAdmin.getName() << "!" << std::endl;
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << "Admin Menu" << std::endl;
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << "1.- Add admin" << std::endl;
        std::cout << "2.- Add Student" << std::endl;
        std::cout << "3.- Add Teacher" << std::endl;
        std::cout << "4.- Add Class" << std::endl;
        std::cout << "5.- Exit" << std::endl;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"
                  << std::endl;
        std::cin >> adminChoice;

        std::string userName{""};
        std::string classDescription{""};
        std::uint32_t userId{};
        std::uint32_t classroomId{};
        std::uint32_t classCapacity{};

        switch (adminChoice)
        {
        case 1:
        {
            std::cout << "Enter name of the admin: " << std::endl;
            std::cin >> userName;
            std::cout << "Enter id of the admin: " << std::endl;
            std::cin >> userId;
            if (validateIdExists(userId))
            {
                addAdmin(userName, userId);
                std::cout << "\nAdmin successfully added to database!" << std::endl;
            }
            else
            {
                std::cout << "\nERROR: ID already exists!" << std::endl;
            }
            break;
        }
        case 2:
        {
            std::cout << "Enter name of the student: " << std::endl;
            std::cin >> userName;
            std::cout << "Enter id of the student: " << std::endl;
            std::cin >> userId;
            if (validateIdExists(userId))
            {
                addStudent(userName, userId);
                std::cout << "\nStudent successfully added to database!" << std::endl;
            }
            else
            {
                std::cout << "\nERROR: ID already exists!" << std::endl;
            }
            break;
        }
        case 3:
        {
            std::cout << "Enter name of the teacher: " << std::endl;
            std::cin >> userName;
            std::cout << "Enter id of the teacher: " << std::endl;
            std::cin >> userId;
            if (validateIdExists(userId))
            {
                addTeacher(userName, userId);
                std::cout << "\nTeacher successfully added to database!" << std::endl;
            }
            else
            {
                std::cout << "\nERROR: ID already exists!" << std::endl;
            }
            break;
        }
        case 4:
        {
            std::cout << "Enter class id: " << std::endl;
            std::cin >> classroomId;
            if (validateIdExists(classroomId))
            {
                std::cout << "Enter id of teacher that will teach this class: "
                          << std::endl;
                std::cin >> userId;
                if (validateTeacherClass(userId))
                {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "Enter class description: " << std::endl;
                std::getline(std::cin, classDescription);
                std::cout << "Enter maximum student capacity: " << std::endl;
                std::cin >> classCapacity;
                addClassroom(classroomId, userId, classDescription,
                             classCapacity);
                std::cout << "\nClass successfully added to database!" << std::endl;
                break;
                }
                else
                {
                    std::cout << "\nERROR: Teacher does not exist!" << std::endl;
                    break;
                }
            }
            else
            {
                std::cout << "\nERROR: ID already exists!" << std::endl;
                break;
            }
        }
        case 5:
        {
            std::cout << "\n[Exiting Admin Menu]" << std::endl;
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
