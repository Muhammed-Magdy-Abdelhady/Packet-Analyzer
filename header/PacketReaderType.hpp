#pragma once

#include <string>
#include <vector>
/*
    PacketReaderType class is responsible for reading packet data from a source.
    It provides methods to read different types of packets and handle the data accordingly.
*/

class PacketReaderType
{
public:
    PacketReaderType() = default;

    PacketReaderType(const PacketReaderType &) = delete;
    PacketReaderType(PacketReaderType &&) noexcept = default;

    PacketReaderType &operator=(const PacketReaderType &) = delete;
    PacketReaderType &operator=(PacketReaderType &&) noexcept = default;

    virtual std::vector<std::string> readPackets() = 0;

    ~PacketReaderType() = default;

private:
    virtual bool open() = 0;
    virtual void close() = 0;
};