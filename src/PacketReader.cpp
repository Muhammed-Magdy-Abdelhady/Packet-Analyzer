#include "PacketReader.hpp"
#include "PacketCreator.hpp"

std::vector<std::unique_ptr<Packet>> PacketReader::readPackets()
{
    std::vector<std::unique_ptr<Packet>> packets;
    if (this->m_reader)
    {
        std::vector<std::string> all_packets_data = std::move(this->m_reader->readPackets());
        for (const auto& packet_data : all_packets_data)
        {
            PacketCreator creator;
            auto packet = creator.createPacket(packet_data);
            packets.push_back(std::move(packet));
        }
    }
    return packets;
}