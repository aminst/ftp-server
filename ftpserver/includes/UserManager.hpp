#ifndef __USER_MANAGER__
#define __USER_MANAGER__

#include <string>
#include <vector>
#include <iostream>

#include "User.hpp"
#include "ConfigParser.hpp"
#include "Exception.hpp"

class UserManager
{
public:
    static User* find_user(std::string user_name);
    static std::vector<User*> users;
};

#endif