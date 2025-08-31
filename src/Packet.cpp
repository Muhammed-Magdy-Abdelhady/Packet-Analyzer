#include "Packet.hpp"
#include "PacketParamsConstants.hpp"

Packet::Packet(std::string packet) : m_packet(packet)
{
    getPacketDataLengthAndFCSPosition();
}

void Packet::getPacketDataLengthAndFCSPosition()
{
    this->m_packetDataLength = (
        this->m_packet.length()
        - PacketParams::PACKET_PREAMBLE_LENGTH
        - PacketParams::PACKET_DESTINATION_ADDRESS_LENGTH
        - PacketParams::PACKET_SOURCE_ADDRESS_LENGTH
        - PacketParams::PACKET_TYPE_LENGTH
        - PacketParams::PACKET_FCS_LENGTH
    );

    this->m_FCSPosition = this->m_packetDataLength + PacketParams::PACKET_DATA_POSITION;
}