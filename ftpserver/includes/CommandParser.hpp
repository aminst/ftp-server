#ifndef __COMMAND_PARSER__
#define __COMMAND_PARSER__

#include <iostream>
#include <sstream>
#include <string>

#include "Request.hpp"

class CommandParser
{
public:
    static Request parse_request(const std::string& input);
private:
    static std::vector<std::string> split_string(const std::string& input);
};

#endif