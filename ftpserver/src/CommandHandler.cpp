#include "CommandHandler.hpp"

using namespace std;

void CommandHandler::run_command(string input)
{
    Request request = CommandParser::parse_request(input);
    string command = request.get_command();
    cout << command << endl;
    if (command == "user")
        ;
    else if (command == "pass")
        ;
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