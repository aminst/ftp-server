#ifndef __LOGGER__
#define __LOGGER__

#include <string>
#include <iostream>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm>

#include "User.hpp"

class Logger
{
public:
    Logger();
    void write_log_message(std::string message);
    void write_log_message(std::string message, User* user);
private:
    std::ofstream log_stream;

    std::string write_current_time();
};

#endif