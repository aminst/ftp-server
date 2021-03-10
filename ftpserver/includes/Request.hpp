#ifndef __REQUEST__
#define __REQUEST__

#include <string>
#include <vector>

class Request
{
public:
    Request(const std::string& command, const std::vector<std::string>& arguments);

    std::string get_command();
    std::vector<std::string> get_arguments();

private:
    std::string command;
    std::vector<std::string> arguments;
};

#endif