#include "CommandHandler.hpp"

using namespace std;


CommandHandler::CommandHandler(int data_fd) : data_fd(data_fd)
{
    user = NULL;
    found_user = NULL;
    is_user_ready = false;
    is_loggedin = false;
    vector<string> temp;
    directory = shell_command_runner("pwd", temp);
}

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
            return response.get_message(LIST_TRANSFER, ls_handler());
        }

        else if (command == "cwd")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(cwd_handler(command, arguments));
        }

        else if (command == "rename")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(rename_handler(command, arguments));
        }

        else if (command == "retr")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(retr_handler(command, arguments));
        }

        else if (command == "help")
        {
            return response.get_message(help_handler());
        }

        else if (command == "quit")
        {
            if(!is_loggedin)
                throw NeedAccountForLogin();
            return response.get_message(quit_handler());
        }
        else
            throw SyntaxErrorInParametersOrArguments();
    }
    catch(Exception& e)
    {
        return response.get_message(e.get_num());
    }
    return response.get_message(ERROR);
}


int CommandHandler::user_handler(std::string username)
{
    if(is_loggedin)
        throw Exception();
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

string CommandHandler::pwd_handler(const std::string command, std::vector<std::string> arguments)
{
    return directory;
}

string CommandHandler::mkd_handler(const std::string command, std::vector<std::string> arguments)
{
    arguments[0] = directory + "/" + arguments[0];
    shell_command_runner("mkdir", arguments);
    return arguments[0];
}

string CommandHandler::ls_handler()
{
    vector<string> arg;
    arg.push_back(directory);
    return shell_command_runner("ls", arg);
}

string CommandHandler::dele_handler(const std::string command, std::vector<std::string> arguments)
{
    if (is_protected(arguments[1]))
        if(!user->get_is_admin())
            throw FileUnavailable();
    arguments[1] = directory + "/" + arguments[1];
    vector<string> temp;
    for(size_t i = 1; i < arguments.size(); i++)
        temp.push_back(arguments[i]);
    if (arguments[0] == "-f")
    {
        shell_command_runner("rm", temp);
        return arguments[1];
    }
    else if (arguments[0] == "-d")
    {
        shell_command_runner("rmdir", temp);
        return arguments[1];
    }
    else
        throw SyntaxErrorInParametersOrArguments();
}

int CommandHandler::cwd_handler(const std::string command, std::vector<std::string> arguments)
{
    vector<string> temp;
    temp.push_back(directory);
    temp.push_back("&& cd");
    temp.push_back(arguments[0]);
    temp.push_back(" && pwd");
    directory = shell_command_runner("cd", temp);
    return SUC_CHANGE;
}

int CommandHandler::rename_handler(const std::string command, std::vector<std::string> arguments)
{
    if (is_protected(arguments[0]))
        if(!user->get_is_admin())
            throw FileUnavailable();
    arguments[0] = directory + "/" + arguments[0];
    arguments[1] = directory + "/" + arguments[1];
    shell_command_runner("mv", arguments);
    return SUC_CHANGE;
}

int CommandHandler::retr_handler(const std::string command, std::vector<std::string> arguments)
{
    if(is_protected(arguments[0]))
        if(!user->get_is_admin())
            throw FileUnavailable();
    arguments[0] = directory + "/" + arguments[0];
    std::error_code ec;
    int file_size_kb = fs::file_size(arguments[0], ec) / 1000;
    if (ec.value() == ENOENT)
        throw FileUnavailable();
    if (user->get_max_download_size() < file_size_kb)
        throw MaxFileSizeExceeded();
    user->set_max_download_size(user->get_max_download_size() - file_size_kb);
    int file_fd = open(arguments[0].c_str(), O_RDONLY);
    sendfile(data_fd, file_fd, NULL, fs::file_size(arguments[0]));
    return SUC_DOWNLOAD;
}

int CommandHandler::quit_handler()
{
    user = NULL;
    is_user_ready = false;
    is_loggedin = false;
    return SUC_QUIT;
}

int CommandHandler::help_handler()
{
    return HELP;
}

bool CommandHandler::is_protected(const std::string file)
{
    for(string _file : FtpServer::protected_files)
    {
        if (file == _file)
        {
            return true;
        }
    }
    return false;
}

  
/// https://stackoverflow.com/a/20617844
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
    result.pop_back();
    result.pop_back();
    return result;
}