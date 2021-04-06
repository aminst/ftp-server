#include "Logger.hpp"

using namespace std;

Logger::Logger()
{
    log_stream.open("log.txt", std::ios::app);
}

string Logger::write_current_time()
{
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    string formatted_time = "[";
    formatted_time.append(ctime(&now_time));
    formatted_time.append("] ");
    formatted_time.erase(remove(formatted_time.begin(), formatted_time.end(), '\n'), formatted_time.end());
    return formatted_time;
}

void Logger::write_log_message(std::string message)
{
    log_stream << write_current_time();
    log_stream << message << endl;
}

void Logger::write_log_message(std::string message, User* user)
{
    log_stream << write_current_time();
    log_stream << "User " << user->get_username() << " ";
    log_stream << message << endl;
}