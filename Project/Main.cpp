#include "dataStore.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    DataStore theDataStore{};

    try
    {
        theDataStore.run();
        theDataStore.printSummary();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}