#pragma once
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T> 
inline T readInput(std::string aPrompt)
{
    T myValue;
    std::cout << aPrompt << std::endl;
    std::cin >> myValue;
    return myValue;
}

template <> 
inline std::string readInput<std::string>(std::string aPrompt)
{
    std::string myValue;
    std::cout << aPrompt << std::endl;
    std::getline(std::cin, myValue);
    return myValue;
}

inline bool isInMenu(std::uint64_t aChoice, const std::vector<std::uint64_t> &aChoices)
{
    for (const auto &myChoice : aChoices)
    {
        if (aChoice == myChoice)
        {
            return true;
        }
    }
    return false;
}

inline bool validateChoices(const std::vector<std::uint64_t> &aChoices)
{
    for (const auto &aChoice : aChoices)
    {
        auto count = std::count(aChoices.begin(), aChoices.end(), aChoice);
        if (count > 1)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
inline std::vector<std::uint64_t> convertToUint64(const std::vector<T> &anEnumChoices)
{
    std::vector<std::uint64_t> myChoices{};
    myChoices.resize(anEnumChoices.size());
    for (std::size_t i = 0; i < anEnumChoices.size(); i++)
    {
        myChoices[i] = static_cast<std::uint64_t>(anEnumChoices[i]);
    }
    return myChoices;
}

template <typename T>
inline T menuSelect(std::string aTitle, const std::vector<T> &anEnumChoices,
                    const std::vector<std::string> &aDescriptions)
{
    auto myChoices = convertToUint64(anEnumChoices);
    auto selectedChoice = menuSelect(aTitle, myChoices, aDescriptions);
    return static_cast<T>(selectedChoice);
}

template <>
inline std::uint64_t menuSelect(std::string aTitle,
                               const std::vector<std::uint64_t> &aChoices,
                               const std::vector<std::string> &aDescriptions)
{
    if (!validateChoices(aChoices))
    {
        throw std::runtime_error("Invalid menu list");
    }

    if (aChoices.size() != aDescriptions.size())
    {
        throw std::runtime_error("Menu strings and enum sizes must match.");
    }

    bool displayedMenu = false;
    std::uint64_t menuChoice{};
    do
    {
        if (displayedMenu)
        {
            std::cout << "\nERROR: Incorrect choice!" << std::endl;
        }
        std::cout << std::endl;
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << aTitle << std::endl;
        std::cout << std::endl;
        for (std::size_t i = 0; i < aChoices.size(); i++)
        {
            std::cout << aChoices[i] << ".- " << aDescriptions[i] << std::endl;
        }
        std::cout << "---------------------------------------------------"
                  << std::endl;
        std::cout << "Please enter a choice: " << std::endl;
        std::cin >> menuChoice;
        displayedMenu = true;
    } while (!isInMenu(menuChoice, aChoices));

    return menuChoice;
}

inline std::uint64_t menuSelect(std::string aTitle,
                               const std::vector<std::string> &aDescriptions)
{
    std::vector<std::uint64_t> myChoices{};
    myChoices.resize(aDescriptions.size());
    for (std::size_t i = 1; i <= aDescriptions.size(); i++)
    {
        myChoices[i - 1] = i;
    }
    return menuSelect(aTitle, myChoices, aDescriptions);
}
