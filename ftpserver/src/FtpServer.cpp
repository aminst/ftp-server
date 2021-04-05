#include "FtpServer.hpp"

#include<errno.h>

using namespace std;

extern int errno;

vector<string> FtpServer::protected_files;

FtpServer::FtpServer()
{
}

void* FtpServer::handle_connection(void* _fd)
{
    int fd = *(int*) _fd;
    CommandHandler* command_handler = new CommandHandler();

    char read_buf[MAX_BUFFER_SIZE];
    string send_buf;
    int client_in_len;
    while (true)
    {
        bzero(read_buf,MAX_BUFFER_SIZE);
        if ((client_in_len = recv(fd, read_buf, sizeof(read_buf), 0)))
        {
                send_buf = command_handler->run_command(string(read_buf));
        }
        if ((client_in_len = send(fd, send_buf.c_str(), sizeof(read_buf), 0)) == -1)
        {
            cout << "Send Command Result Error!" << endl;
        }

    }
    return NULL;
}

void FtpServer::run()
{
    struct sockaddr_in server_sin;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        cout << "Socket Creation Error!" << endl;
        exit(EXIT_FAILURE);
    }
    server_sin.sin_port = htons(5000);
    server_sin.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_sin.sin_family = AF_INET;

    int true_flag = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char*)&true_flag, sizeof(int)) == -1)
    {
        cout << "Set Option Error!" << endl;
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr*)& server_sin, sizeof(server_sin)) == -1)
    {
        cout << "Bind Error!" << endl;
        cout << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) == -1)
    {
        cout << "vectoren Error!" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client_sin;
    int client_in_len = sizeof(client_sin);
    int thread_number = 0;
    vector<thread> new_threads;
    while (true)
    {
        int new_server_fd = accept(server_fd, (struct sockaddr*)& client_sin, (socklen_t*)&client_in_len);
        if (new_server_fd == -1)
        {
            cout << "Accept Error!" << endl;
            cout << strerror(errno) << endl;
        }   
        
        thread new_thread(&FtpServer::handle_connection, this, (void*)&new_server_fd);
        new_threads.push_back(move(new_thread));
        thread_number++;
    }
    for (thread& thread : new_threads)
    {
        if (thread.joinable())
            thread.join();
    }
    // close(server_fd);
    // close(new_server_fd);
}

