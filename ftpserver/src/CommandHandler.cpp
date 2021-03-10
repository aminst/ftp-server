#include "CommandHandler.hpp"

using namespace std;

void CommandHandler::run_command(string input)
{
    Request request = CommandParser::parse_request(input);
}