#include "CommandHandler.hpp"

using namespace std;

void CommandHandler::run_command(string input)
{
    Request request = CommandParser::parse_request(input);
    string command = request.get_command();
    vector<string> arguments = request.get_arguments();

    if (command == "user")
    {
    
        found_user = UserManager::user_finder(arguments[0]);
        is_user_ready = true;
    }
    else if (command == "pass")
    {
        if(!is_user_ready)
        {
            throw BadSequenceOfCommands();
        }
        else
        {
                user = pass_checker(found_user->get_password(), arguments[0]) ? found_user : NULL;
        }
        
    }

    else if (command == "pwd")
        ;
    else if (command == "mkd")
        ;
    else if (command == "dele")
        ;
    else if (command == "ls")
        ;
    else if (command == "cwd")
        ;
    else if (command == "rename")
        ;
    else if (command == "retr")
        ;
    else if (command == "help")
        ;
    else if (command == "quit")
        ;
    else
        ;
}


bool CommandHandler::pass_checker(std::string found_user_pass, std::string pass)
{
    if(found_user_pass == pass)
    {
        return true;
    }
    else
    {
        is_user_ready = false;
        throw InvalidUsernameAndPassword();
    }
}