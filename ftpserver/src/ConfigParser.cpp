#include "ConfigParser.hpp"

using namespace std;

ConfigParser::ConfigParser(const string& config_file_path) : config_file_path(config_file_path)
{
    parse();
}

void ConfigParser::parse()
{
    ifstream file(config_file_path);
    json json;
    file >> json;
    for (auto& user: json["users"])
    {
        users.push_back(
            new User(
            user["user"].get<string>(),
            user["password"].get<string>(),
            user["admin"].get<string>() == "true",
            stoi(user["size"].get<string>()))
        );
    }
    for (auto& protected_file: json["files"])
        protected_files.push_back(protected_file.get<string>());
}

vector<User*> ConfigParser::get_users()
{
    return users;
}
vector<string> ConfigParser::get_protected_files()
{
    return protected_files;
}