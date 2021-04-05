#ifndef __COMMAND_HANDLER__
#define __COMMAND_HANDLER__

#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "CommandParser.hpp"
#include "Request.hpp"
#include "User.hpp"
#include "FtpServer.hpp"
#include "Exception.hpp"
#include "Response.hpp"

class CommandHandler
{
public:
    CommandHandler();
    std::string run_command(std::string input);
    
private:
    User* user;
    User* found_user;
    bool is_user_ready;
    bool is_loggedin;
    std::string directory;
    bool pass_checker(std::string found_user_pass, std::string pass);
    int user_handler(std::string username);
    int pass_handler(std::string pass);
    std::string shell_command_runner(const std::string command, const std::vector<std::string> arguments);
    std::string pwd_handler(const std::string command, std::vector<std::string> arguments);
    std::string mkd_handler(const std::string command, std::vector<std::string> arguments);
    std::string dele_handler(const std::string command, std::vector<std::string> arguments);
    std::string ls_handler();
    int cwd_handler(const std::string command, std::vector<std::string> arguments);
    int rename_handler(const std::string command, std::vector<std::string> arguments);
    std::string retr_handler(const std::string command, std::vector<std::string> arguments); 
    int help_handler(); 
    int quit_handler(); 
    bool is_protected(const std::string file);
};

#endif