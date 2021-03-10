#include "FtpServer.hpp"

int main(int argc, char const *argv[])
{
    FtpServer ftp_server = FtpServer();
    ftp_server.run();
    return 0;
}
