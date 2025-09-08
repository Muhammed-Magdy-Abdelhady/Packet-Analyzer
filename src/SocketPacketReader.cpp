#include "SocketPacketReader.hpp"

SocketPacketReader::SocketPacketReader(int port)
    : m_server(port)
{
    this->open();
}

std::vector<std::string> SocketPacketReader::readPackets()
{
    std::vector<std::string> packets;

    while (this->m_server.is_connected())
    {
        std::string packet = std::move(this->m_server.read_line());
        if (!packet.empty())
        {
            packets.push_back(std::move(packet));
        }
    }
    return packets;
}

bool SocketPacketReader::open()
{
    return this->m_server.initialize();
}
