#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

using namespace std;

int main(int argc, char const *argv[])
{
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        cout << "Socket Creation Error!" << endl; //
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_sin;
    server_sin.sin_port = htons(5000);
    server_sin.sin_addr.s_addr = inet_addr("127.0.0.1");;
    server_sin.sin_family = AF_INET;

    if (connect(client_fd,(struct sockaddr*)&server_sin, sizeof(server_sin)) == -1)
    {
        cout << "Connect Error!" << endl;
        return EXIT_FAILURE;
    }

    char buf[MAX_BUFFER_SIZE] = "salammmmmmmmmmmmmmmmmm ^_^";
    send(client_fd, buf, sizeof(buf), 0);

    return 0;
}
