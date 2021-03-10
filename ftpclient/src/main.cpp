#include "FtpClient.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    FtpClient ftp_client = FtpClient();
    ftp_client.run();

    return 0;
}
