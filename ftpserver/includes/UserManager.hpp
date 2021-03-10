#ifndef __USER_MANAGER__
#define __USER_MANAGER__

#include <string>
#include <vector>
#include <iostream>

#include "User.hpp"

class UserManager
{
public:
    UserManager(std::vector<User*> users);

private:
    std::vector<User*> users;
};

#endif