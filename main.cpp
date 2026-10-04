#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        std::cerr << "Failed to create socket" << std::endl;
        return -1;
    }

    sockaddr_in address;
    address.

        return 0;
}