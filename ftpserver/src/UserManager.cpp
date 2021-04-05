#include "UserManager.hpp"

using namespace std;

std::vector<User*> UserManager::users;

User* UserManager::find_user(std::string username)
{
    for(User* user : UserManager::users)
    {
        if(user->get_username() == username)
            return user;
    }
    throw InvalidUsernameAndPassword();
}