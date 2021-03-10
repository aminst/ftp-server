#include "User.hpp"

using namespace std;

User::User(const string& username,
        const string& password,
        const bool& is_admin,
        const int& max_download_size)
        : username(username), password(password), is_admin(is_admin), max_download_size(max_download_size)
{
}