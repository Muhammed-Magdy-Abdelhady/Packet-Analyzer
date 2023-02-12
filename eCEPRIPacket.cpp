#include "eCEPRIPacket.h"
#include "PacketParams.h"
#include "NumericalTypeConverter.h"

eCEPRIPacket::eCEPRIPacket(const std::string& packet)
    : m_packet(packet)
{
    m_packetType = eCEPRI;
    getPacketDataLengthAndFCSPosition();
}

eCEPRIPacket::~eCEPRIPacket()
{
}

void eCEPRIPacket::getPacketDataLengthAndFCSPosition()
{
    PACKET_DATA_LENGTH = m_packet.length() - PACKET_PREAMBLE_LENGTH - PACKET_DESTINATION_ADDRESS_LENGTH
                                           - PACKET_SOURCE_ADDRESS_LENGTH - PACKET_TYPE_LENGTH - PACKET_FCS_LENGTH;

    PACKET_FCS_POSITION = PACKET_DATA_POSITION + PACKET_DATA_LENGTH;
}

Packet::PacketProtocolType eCEPRIPacket::getPacketType()
{
    return m_packetType;
}


std::vector<std::string> eCEPRIPacket::breakDownPacket()
{
    std::vector<std::string> borkenDownPacket(11);
    std::string eCEPRIPacketDataBody = m_packet.substr(PACKET_DATA_POSITION, PACKET_DATA_LENGTH);

    int protocolVersion = NumericalTypeConverter::hexCharToInt(
        eCEPRIPacketDataBody[eCEPRI_PACKET_PROTOCOL_VERSION_POSITION]
    );

    int concatenationIndicator = NumericalTypeConverter::hexCharToInt(
        eCEPRIPacketDataBody[eCEPRI_PACKET_CONCATENATION_INDICATOR_POSITION]
    );

    borkenDownPacket[0] = m_packet;
    borkenDownPacket[1] = "CRC: " + m_packet.substr(PACKET_FCS_POSITION, PACKET_FCS_LENGTH);
    borkenDownPacket[2] = "Concatenation Indicator: " + std::to_string(concatenationIndicator);
    borkenDownPacket[3] = "Destination Address: " + m_packet.substr(PACKET_DESTINATION_ADDRESS_POSITION, PACKET_DESTINATION_ADDRESS_LENGTH);
    borkenDownPacket[4] = "Message Type: " + eCEPRIPacketDataBody.substr(eCEPRI_PACKET_MESSAGE_TYPE_POSITION, eCEPRI_PACKET_MESSAGE_TYPE_LENGTH);
    borkenDownPacket[5] = "Payload Size: " + eCEPRIPacketDataBody.substr(eCEPRI_PACKET_PAYLOAD_SIZE_POSITION, eCEPRI_PACKET_PAYLOAD_SIZE_LENGTH);
    borkenDownPacket[6] = "Protocol Version: " + std::to_string(protocolVersion);
    borkenDownPacket[7] = "RTC ID: " + eCEPRIPacketDataBody.substr(eCEPRI_PACKET_RTC_ID_POSITION, eCEPRI_PACKET_RTC_ID_LENGTH);
    borkenDownPacket[8] = "Sequence ID: " + eCEPRIPacketDataBody.substr(eCEPRI_PACKET_SEQ_ID_POSITION, eCEPRI_PACKET_SEQ_ID_LENGTH);
    borkenDownPacket[9] = "Source Address: " + m_packet.substr(PACKET_SOURCE_ADDRESS_POSITION, PACKET_SOURCE_ADDRESS_LENGTH);
    borkenDownPacket[10] = "Type: " + m_packet.substr(PACKET_TYPE_POSITION, PACKET_TYPE_LENGTH);

    return borkenDownPacket;
}

bool eCEPRIPacket::checkConcatenationIndicator(int concatenationIndicator)
{
    return (concatenationIndicator & eCEPRI_PACKET_CONCATENATION_INDICATOR_MASK);
}