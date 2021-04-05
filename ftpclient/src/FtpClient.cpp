#include "FtpClient.hpp"

using namespace std;

void FtpClient::run()
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        cout << "Socket Creation Error!" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_sin;
    server_sin.sin_port = htons(5000);
    server_sin.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_sin.sin_family = AF_INET;

    if (connect(client_fd,(struct sockaddr*)&server_sin, sizeof(server_sin)) == -1)
    {
        cout << "Connect Error!" << endl;
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUFFER_SIZE];
    string command;
    while(getline(cin, command))
    {
        strcpy(buf, command.c_str());
        send(client_fd, buf, sizeof(buf), 0);
        recv(client_fd, buf, sizeof(buf), 0);
        cout << buf << endl;
    }

    close(client_fd); // does this run after Ctrl+C??? NOOOOOO
}