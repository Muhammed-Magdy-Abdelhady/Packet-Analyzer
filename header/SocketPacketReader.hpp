#pragma once

#include "PacketReaderType.hpp"
#include "SocketServer.hpp"

class SocketPacketReader : public PacketReaderType
{
public:
    SocketPacketReader(int port);
    SocketPacketReader(const SocketPacketReader &) = delete;
    SocketPacketReader(SocketPacketReader &&) noexcept = default;
    SocketPacketReader &operator=(const SocketPacketReader &) = delete;
    SocketPacketReader &operator=(SocketPacketReader &&) noexcept = default;
    ~SocketPacketReader() = default;

    std::vector<std::string> readPackets() override;

private:
    bool open() override;
    void close() override {};

    SocketServer m_server;
};
