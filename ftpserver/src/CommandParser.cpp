#include "CommandParser.hpp"

using namespace std;

Request CommandParser::parse_request(const string& input)
{
    vector<string> splitted = split_string(input);
    string command = splitted[0];
    vector<string> arguments(splitted.begin() + 1, splitted.end());
    return Request(command, arguments);
}

vector<string> CommandParser::split_string(const string& input)
{
    vector<string> parsed_request;
    stringstream ss(input);
    string str;
    while (getline(ss, str, ' '))
        parsed_request.push_back(str);

    return parsed_request;
}