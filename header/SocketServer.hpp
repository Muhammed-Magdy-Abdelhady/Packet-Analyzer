#pragma once

#include <string>
#include <vector>

#if defined(_WIN32)

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#endif

class SocketServer
{
public:
    SocketServer(int port);
    ~SocketServer();

    bool initialize();
    bool is_connected();
    std::string read_line();
private:
    void closeSocket();

    int m_port;
    int m_server_fd;
    int m_client_fd;
};