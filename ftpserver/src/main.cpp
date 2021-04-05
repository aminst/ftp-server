#include "FtpServer.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    constexpr int CONFIG_FILE_PATH_INDEX = 1;

    FtpServer ftp_server = FtpServer();
    UserManager::users = ConfigParser(argv[CONFIG_FILE_PATH_INDEX]).get_users();
    FtpServer::protected_files = ConfigParser(argv[CONFIG_FILE_PATH_INDEX]).get_protected_files();
    ftp_server.run();
    return 0;
}
