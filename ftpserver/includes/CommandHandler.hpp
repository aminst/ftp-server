#ifndef __COMMAND_HANDLER__
#define __COMMAND_HANDLER__

#include <string>

#include "CommandParser.hpp"
#include "Request.hpp"

class CommandHandler
{
public:
    void run_command(std::string input);
};

#endif