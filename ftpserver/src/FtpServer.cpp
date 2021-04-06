#include "FtpServer.hpp"

#include<errno.h>

using namespace std;


vector<string> FtpServer::protected_files;

FtpServer::FtpServer()
{
}

void* FtpServer::handle_connection(void* _command_fd, void* _data_fd)
{
    int command_fd = *(int*) _command_fd;
    int data_fd = *(int*) _data_fd;  
    CommandHandler* command_handler = new CommandHandler(data_fd);

    char read_buf[MAX_BUFFER_SIZE];
    string send_buf;
    int client_in_len;
    while (true)
    {
        bzero(read_buf,MAX_BUFFER_SIZE);
        if (recv(command_fd, read_buf, sizeof(read_buf), 0) > 0)
        {   
            send_buf = command_handler->run_command(string(read_buf));
        }
        else
            return nullptr;
        if ((client_in_len = send(command_fd, send_buf.c_str(), sizeof(read_buf), 0)) == -1)
        {
            cout << "Send Command Result Error!" << endl;
        }
    }
    return NULL;
}

int FtpServer::run_socket(int port)
{
    struct sockaddr_in server_sin;

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        cout << "Socket Creation Error!" << endl;
        exit(EXIT_FAILURE);
    }
    server_sin.sin_port = htons(port);
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
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) == -1)
    {
        cout << "listen Error!" << endl;
        exit(EXIT_FAILURE);
    }
    return server_fd;
}

void FtpServer::run()
{
    // TODO: read from config or blah blah blah
    int command_fd = run_socket(5000);
    int data_fd = run_socket(5001);

    struct sockaddr_in client_sin;
    int client_in_len = sizeof(client_sin);
    int thread_number = 0;
    vector<thread> new_threads;
    while (true)
    {
        int new_command_fd = accept(command_fd, (struct sockaddr*)& client_sin, (socklen_t*)&client_in_len);
        int new_data_fd = accept(data_fd, (struct sockaddr*)& client_sin, (socklen_t*)&client_in_len);
        if (new_command_fd == -1 || new_data_fd == -1)
        {
            cout << "Accept Error!" << endl;
        }
        
        thread new_thread(&FtpServer::handle_connection, this, (void*)&new_command_fd, (void*)&new_data_fd);
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

