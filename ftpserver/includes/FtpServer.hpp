#ifndef __FTP_SERVER__
#define __FTP_SERVER__

#include <iostream>
#include <string>
#include <thread>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "CommandHandler.hpp"

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

class FtpServer
{
public:
    void run();
    void* handle_connection(void* fd);

private:
    CommandHandler command_handler;
};

#endif