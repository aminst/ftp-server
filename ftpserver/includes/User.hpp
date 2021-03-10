#ifndef __USER__
#define __USER__

#include <string>

class User
{
public:
    User(
        const std::string& username,
        const std::string& password,
        const bool& is_admin,
        const int& max_download_size
    );

private:
    std::string username;
    std::string password;
    bool is_admin;
    int max_download_size;
};

#endif