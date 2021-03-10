#include "Request.hpp"

using namespace std;

Request::Request(const string& command, const vector<string>& arguments)
    : command(command), arguments(arguments)
{
}

string Request::get_command()
{
    return command;
}
vector<string> Request::get_arguments()
{
    return arguments;
}