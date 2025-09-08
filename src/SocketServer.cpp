#include "SocketServer.hpp"
#include <stdexcept>
#include <array>

SocketServer::SocketServer(int port)
    : m_port(port), m_server_fd(-1)
{
#if defined(_WIN32)
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        throw std::runtime_error("WSAStartup failed");
    }
#endif
}
SocketServer::~SocketServer()
{
    this->closeSocket();
#if defined(_WIN32)
    WSACleanup();
#endif
}

bool SocketServer::initialize()
{
    this->m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->m_server_fd < 0)
    {
        throw std::runtime_error("Failed to create socket");
    }

    sockaddr_in addr;
    socklen_t addrLen = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(this->m_port);

    if (bind(this->m_server_fd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0)
    {
        this->closeSocket();
        throw std::runtime_error("Failed to bind Socket");
    }

    if (listen(this->m_server_fd, 3) < 0)
    {
        this->closeSocket();
        throw std::runtime_error("Failed to listen");
    }
    this->m_client_fd = accept(
        this->m_server_fd,
        reinterpret_cast<sockaddr *>(&addr),
        &addrLen);

    if (this->m_client_fd < 0)
    {
        this->closeSocket();
        throw std::runtime_error("Failed to accept socket");
    }

    return true;
}

bool SocketServer::is_connected()
{
    return this->m_client_fd >= 0;
}

std::string SocketServer::read_line()
{
    if (!is_connected())
    {
        throw std::runtime_error("Client not connected");
    }
    const int BUFFER_SIZE = 1024;
    std::array<char, BUFFER_SIZE> buffer;
    ssize_t bytes_read = recv(this->m_client_fd, buffer.data(), buffer.size() - 1, 0);
    if (bytes_read < 0)
    {
        throw std::runtime_error("Failed to read from socket");
    }

    if (bytes_read == 0)
    {
        this->closeSocket();
        return std::string();
    }

    buffer[bytes_read] = '\0';
    return std::string(buffer.data());
}

void SocketServer::closeSocket()
{
    if (this->m_client_fd >= 0)
    {
#if defined(_WIN32)
        closesocket(this->m_client_fd);
#else
        close(this->m_client_fd);
#endif
        this->m_client_fd = -1;
    }
    if (this->m_server_fd >= 0)
    {
#if defined(_WIN32)
        closesocket(this->m_server_fd);
#else
        close(this->m_server_fd);
#endif
        this->m_server_fd = -1;
    }
}