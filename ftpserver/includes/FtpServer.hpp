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

#include "UserManager.hpp"
#include "CommandHandler.hpp"
#include "ConfigParser.hpp"
#include "User.hpp"
#include "Response.hpp"

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

class FtpServer
{
public:
    FtpServer();
    void run();
    int run_socket(int port);
    void* handle_connection(void* command_fd, void* data_fd);

    static std::vector<std::string> protected_files;
};

#endif