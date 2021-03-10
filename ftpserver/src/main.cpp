#include "FtpServer.hpp"

int main(int argc, char const *argv[])
{
    constexpr int CONFIG_FILE_PATH_INDEX = 1;

    FtpServer ftp_server = FtpServer(argv[CONFIG_FILE_PATH_INDEX]);
    ftp_server.run();
    return 0;
}
