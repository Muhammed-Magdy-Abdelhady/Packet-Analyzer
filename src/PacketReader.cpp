#include "PacketReader.hpp"

std::vector<std::string> PacketReader::readPackets()
{
    if (this->m_reader)
    {
        std::vector<std::string> packets = std::move(this->m_reader->readPackets());
        return packets;
    }
    return {};
}