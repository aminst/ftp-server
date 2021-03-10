#include "FtpServer.hpp"

int main(int argc, char const *argv[])
{
    FtpServer ftp_server = FtpServer();
    ftp_server.start();
    return 0;
}
