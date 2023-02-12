#include "PacketAnalyzer.h"
#include "PacketParams.h"
PacketAnalyzer::PacketAnalyzer()
{
}

PacketAnalyzer::~PacketAnalyzer()
{
}

Packet::PacketProtocolType PacketAnalyzer::getPacketProtocolType(const std::string& packet)
{
    std::string packetType = packet.substr(PACKET_TYPE_POSITION, PACKET_TYPE_LENGTH);

    if (packetType == eCEPRI_PACKET_TYPE_VALUE)
    {
        return Packet::eCEPRI;
    }
    else
    {
        return Packet::NORMAL;
    }
}

std::unique_ptr<Packet> PacketAnalyzer::AnalyzePacket(const std::string& packet)
{
    std::unique_ptr<Packet> m_packet;
    auto packetProtocolType = getPacketProtocolType(packet);

    switch (packetProtocolType)
    {
    case Packet::eCEPRI:
        m_packet = std::make_unique<eCEPRIPacket>(packet);
        break;
    case Packet::NORMAL:
        m_packet = std::make_unique<rawPacket>(packet);
        break;
    default:
        break;
    }

    return m_packet;
}

std::vector<std::unique_ptr<Packet>> PacketAnalyzer::AnalyzePackets(const std::vector<std::string>& packets)
{
    std::vector<std::unique_ptr<Packet>> m_packets;

    for (auto packet : packets)
    {
        m_packets.push_back(AnalyzePacket(packet));
    }

    return m_packets;
}
