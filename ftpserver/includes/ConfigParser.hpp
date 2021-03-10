#ifndef __CONFIG_PARSER__
#define __CONFIG_PARSER__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "User.hpp"
#include "Json.hpp"

using json = nlohmann::json;

class ConfigParser
{
public:
    ConfigParser(const std::string& config_file_path);
    std::vector<User*> get_users();
    std::vector<std::string> get_protected_files();
private:
    std::string config_file_path;
    std::vector<User*> users;
    std::vector<std::string> protected_files;

    void parse();
};

#endif