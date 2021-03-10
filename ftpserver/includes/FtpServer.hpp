#ifndef __FTP_SERVER__
#define __FTP_SERVER__

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

class FtpServer
{
public:
    void start();
};

#endif