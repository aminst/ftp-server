#include "FtpClient.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    FtpClient ftp_client = FtpClient();
    ftp_client.start();
    
    return 0;
}
