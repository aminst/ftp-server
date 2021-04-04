#ifndef __USER_MANAGER__
#define __USER_MANAGER__

#include <string>
#include <vector>
#include <iostream>

#include "User.hpp"
#include "ConfigParser.hpp"
#include "Exceptions.hpp"

class UserManager
{
public:
    //UserManager(std::vector<User*> users);
    //std::vector<User*> get_users();
    static User* user_finder(std::string user_name);
    static std::vector<User*> users;
};

#endif