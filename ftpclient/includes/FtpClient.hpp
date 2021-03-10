#ifndef __FTP_CLIENT__
#define __FTP_CLIENT__

#include <iostream>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

class FtpClient
{
public:
    void run();
};

#endif