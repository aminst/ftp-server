#include "FtpServer.hpp"

using namespace std;

void* FtpServer::handle_connection()
{
    // int fd = *(int*) _fd;

    // char buf[MAX_BUFFER_SIZE];
    // int client_in_len;
    // while (true)
    // {
    //     if ((client_in_len = recv(fd, buf, sizeof(buf), 0)))
    //         command_handler.run_command(string(buf));
    // }
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

    if (bind(server_fd, (struct sockaddr*)& server_sin, sizeof(server_sin)) == -1)
    {
        cout << "Bind Error!" << endl;
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CONNECTIONS) == -1)
    {
        cout << "Listen Error!" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in client_sin;
    // pthread_t ptid[MAX_CONNECTIONS];
    int client_in_len;
    int thread_number = 0;
    while (true)
    {
        int new_server_fd = accept(server_fd, (struct sockaddr*)& client_sin, (socklen_t*)&client_in_len);
        if (new_server_fd == -1)
        {
            cout << "Accept Error!" << endl;
        }   
        thread new_thread(&FtpServer::handle_connection, this);
        // pthread_create(&ptid[thread_number], NULL, &FtpServer::handle_connection, (void*)&new_server_fd);
        thread_number++;
    }
    
    // close(server_fd);
    // close(new_server_fd);
}

// void thread(fd)
// {
//     string user;
//     cin >> user;

//     string pass;
//     cin >> pass;

//     // UserManager.findUser()
//     User* loggedin_user;

// }


