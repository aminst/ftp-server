#include "UserManager.hpp"

using namespace std;


// std::vector<User*> UserManager::get_users()
// {
//     return users;
// }
std::vector<User*> UserManager::users;

User* UserManager::user_finder(std::string username)
{
    for(User* user : UserManager::users)
    {
        if(user->get_username() == username)
        {
            cout << "‫‪331:‬‬ ‫‪User‬‬ ‫‪name‬‬ ‫‪okay,‬‬ ‫‪need‬‬ ‫‪password.‬‬" << endl;
            return user;
        }
    }
    throw InvalidUsernameAndPassword();
}