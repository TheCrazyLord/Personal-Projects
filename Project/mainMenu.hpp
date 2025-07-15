#pragma once
#include "menuHelper.hpp"
#include <string>
#include <vector>

class Menu1
{
  public:
    enum class Options
    {
        ENTER_USER_ID = 1,
        LIST_USERS,
        EXIT
    };

    Options getMenuOption()
    {
        return menuSelect(std::string{"Main Menu"}, theEnumOptions,
                          theEnumStrings);
    }

  private:
    inline static const std::vector<Options> theEnumOptions{
        Options::ENTER_USER_ID, Options::LIST_USERS, Options::EXIT};
    inline static const std::vector<std::string> theEnumStrings{
        "Select User Id", "List Users", "Exit"};
};
