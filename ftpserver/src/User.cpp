#include "User.hpp"

using namespace std;

User::User(const string& username,
        const string& password,
        const bool& is_admin,
        const int& max_download_size)
        : username(username), password(password), is_admin(is_admin), max_download_size(max_download_size)
{
}

std::string User::get_username()
{
        return username;
}

std::string User::get_password()
{
        return password;
}

bool User::get_is_admin()
{
        return is_admin;
}

int User::get_max_download_size()
{
        return max_download_size;
}