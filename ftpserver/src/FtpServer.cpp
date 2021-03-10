#include "FtpServer.hpp"

using namespace std;

void FtpServer::start()
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
    int client_in_len;
    int new_server_fd = accept(server_fd, (struct sockaddr*)& client_sin, (socklen_t*)&client_in_len);
    if (new_server_fd == -1)
    {
        cout << "Accept Error!" << endl;
    }

    char buf[MAX_BUFFER_SIZE];
    while (true)
    {
        if ((client_in_len = recv(new_server_fd, buf, sizeof(buf), 0)))
            cout << buf << endl;
    }
    
    close(server_fd);
    close(new_server_fd);
}