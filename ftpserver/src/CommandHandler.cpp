#include "CommandHandler.hpp"

using namespace std;

string CommandHandler::run_command(string input)
{
    Request request = CommandParser::parse_request(input);
    string command = request.get_command();
    vector<string> arguments = request.get_arguments();

    Response response;
    try
    {
        if (command == "user")
        {
            return response.get_message(user_handler(arguments[0]));
        }

        else if (command == "pass")
        {
            return response.get_message(pass_handler(arguments[0]));
        }
        
        else if (command == "pwd")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(PWD_DIRECTORY, pwd_handler(command, arguments));
        }

        else if (command == "mkd")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(MKD_DIRECTORY, mkd_handler(command, arguments));
        }

        else if (command == "dele")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(DELETE, dele_handler(command, arguments));
        }

        else if (command == "ls")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(LIST_TRANSFER, ls_handler(command, arguments));
        }
        // else if (command == "cwd")
        //     return;
        // else if (command == "rename")
        //     return ;
        // else if (command == "retr")
        //     return;
        // else if (command == "help")
        //     return;
        // else if (command == "quit")
        //     return;
        else
            throw SyntaxErrorInParametersOrArguments();
    }
    catch(Exception& e)
    {
        return response.get_message(e.get_num());
    }
    return "uuuuuuuuuuuu";
}


int CommandHandler::user_handler(std::string username)
{
    found_user = UserManager::find_user(username);
    is_user_ready = true;
    return USERNAME_OKAY;
}

int CommandHandler::pass_handler(std::string pass)
{
    if(!is_user_ready)
    {
        throw BadSequenceOfCommands();
    }
    else
    {
        if(pass_checker(found_user->get_password(), pass))
        {
            user = found_user;
            is_loggedin = true;
        }
        return USER_LOGGEDIN;
    }
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

string CommandHandler::pwd_handler(const std::string command, const std::vector<std::string> arguments)
{
    return shell_command_runner(command, arguments);
}

string CommandHandler::mkd_handler(const std::string command, const std::vector<std::string> arguments)
{
    shell_command_runner("mkdir", arguments);
    return arguments[0];
}

string CommandHandler::ls_handler(const std::string command, const std::vector<std::string> arguments)
{
    return shell_command_runner(command, arguments);
}

string CommandHandler::dele_handler(const std::string command, const std::vector<std::string> arguments)
{
    
    vector<string> temp;
    for(int i = 1; i < arguments.size(); i++)
    {
        temp.push_back(arguments[i]);
    }
    if (arguments[0] == "-f")
    {
        return shell_command_runner(command, temp) ;
    }
    else if (arguments[0] == "-d")
    {
        return shell_command_runner(command, temp);
    }
    else
        throw SyntaxErrorInParametersOrArguments();
}

/*  
    This method is copied from:

           https://stackoverflow.com/a/20617844
*/
string CommandHandler::shell_command_runner(const std::string command, const std::vector<std::string> arguments)
{
    char tmpname [L_tmpnam];
    std::tmpnam ( tmpname );
    std::string cmd = command + " ";
    for(std::string str : arguments)
    {
        cmd += str + " ";
    }
    cmd = cmd + ">> " + tmpname;
    cout << cmd << endl;
    if (std::system(cmd.c_str()) != 0)
        throw Exception(); 
    std::ifstream file(tmpname, std::ios::in | std::ios::binary );
    std::string result;
    if (file) {
        while (!file.eof()) result.push_back(file.get())
            ;
        file.close();
    }
    remove(tmpname);
    return result;
}