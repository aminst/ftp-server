#include "FtpClient.hpp"

using namespace std;

void* FtpClient::get_file(void* _client_data_fd)
{
    int client_data_fd = *(int*) _client_data_fd;
    char data_buf[MAX_BUFFER_SIZE] = {0};
    if (recv(client_data_fd, data_buf, sizeof(data_buf), 0) > 0)
    {
        FILE *file = fopen("downloaded_file", "wb");
        int size = 0;
        for (int i = 0; i < MAX_BUFFER_SIZE; i++)
        {
            if (data_buf[i] != 0)
                size++;
            else
                break;
        }
        fwrite(data_buf, size, 1, file);
        fclose(file);
    }
    return NULL;
}

void FtpClient::run()
{
    int client_command_fd = socket(AF_INET, SOCK_STREAM, 0);
    int client_data_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_command_fd == -1)
    {
        cout << "Socket Creation Error!" << endl;
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_command_sin;
    server_command_sin.sin_port = htons(5000);
    server_command_sin.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_command_sin.sin_family = AF_INET;

    struct sockaddr_in server_data_sin;
    server_data_sin.sin_port = htons(5001);
    server_data_sin.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_data_sin.sin_family = AF_INET;

    if (connect(client_command_fd,(struct sockaddr*)&server_command_sin, sizeof(server_command_sin)) == -1)
    {
        cout << "Connect Error!" << endl;
        exit(EXIT_FAILURE);
    }
    if (connect(client_data_fd,(struct sockaddr*)&server_data_sin, sizeof(server_data_sin)) == -1)
    {
        cout << "Connect Error!" << endl;
        exit(EXIT_FAILURE);
    }

    thread new_thread(&FtpClient::get_file, this, (void*)&client_data_fd);

    char buf[MAX_BUFFER_SIZE];

    string command;
    while(getline(cin, command))
    {
        strcpy(buf, command.c_str());
        send(client_command_fd, buf, sizeof(buf), 0);
        recv(client_command_fd, buf, sizeof(buf), 0);
        cout << buf << endl;
    }

    close(client_command_fd);
}