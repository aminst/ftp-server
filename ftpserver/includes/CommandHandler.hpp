#ifndef __COMMAND_HANDLER__
#define __COMMAND_HANDLER__

#include <string>

#include "CommandParser.hpp"
#include "Request.hpp"
#include "User.hpp"
#include "FtpServer.hpp"
#include "Exceptions.hpp"

class CommandHandler
{
public:
    CommandHandler()
    {
        user = NULL;
        found_user = NULL;
        is_user_ready = false;
    }
    void run_command(std::string input);
    
private:
    User* user;
    User* found_user;
    bool is_user_ready;
    bool pass_checker(std::string found_user_pass, std::string pass);
};

#endif