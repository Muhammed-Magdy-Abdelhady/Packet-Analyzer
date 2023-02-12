#include "rawPacket.h"
#include "PacketParams.h"

rawPacket::rawPacket(const std::string& packet) : m_packet(packet)
{
    m_packetType = NORMAL;
    getPacketDataLengthAndFCSPosition();
}

rawPacket::~rawPacket()
{
}

Packet::PacketProtocolType rawPacket::getPacketType()
{
    return m_packetType;
}

void rawPacket::getPacketDataLengthAndFCSPosition()
{
    PACKET_DATA_LENGTH = m_packet.length() - PACKET_PREAMBLE_LENGTH - PACKET_DESTINATION_ADDRESS_LENGTH
        - PACKET_SOURCE_ADDRESS_LENGTH - PACKET_TYPE_LENGTH - PACKET_FCS_LENGTH;

    PACKET_FCS_POSITION = PACKET_DATA_POSITION + PACKET_DATA_LENGTH;
}

std::vector<std::string> rawPacket::breakDownPacket()
{
    std::vector<std::string> borkenDownPacket(5);
    
    borkenDownPacket[0] = m_packet;
    borkenDownPacket[1] = "CRC: " + m_packet.substr(PACKET_FCS_POSITION, PACKET_FCS_LENGTH);
    borkenDownPacket[2] = "Destination Address: " + m_packet.substr(PACKET_DESTINATION_ADDRESS_POSITION, PACKET_DESTINATION_ADDRESS_LENGTH);
    borkenDownPacket[3] = "Source Address: " + m_packet.substr(PACKET_SOURCE_ADDRESS_POSITION, PACKET_SOURCE_ADDRESS_LENGTH);
    borkenDownPacket[4] = "Type: " + m_packet.substr(PACKET_TYPE_POSITION, PACKET_TYPE_LENGTH);

    return borkenDownPacket;
}