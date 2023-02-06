#include "PacketAnalyzer.h"
#include "PacketAnalyzerParams.h"
#include <iostream>

PacketAnalyzer::PacketAnalyzer(const std::string& packet):
    m_packet(packet)
{
    m_analyzedPacket["Whole Packet"] = m_packet;
}

PacketAnalyzer::~PacketAnalyzer()
{
}

void PacketAnalyzer::AnalyzePacket()
{
    getPacketProtocolType();
    getPacketDataLengthAndFCSPosition();
    AnalyzePacketHeader();
    AnalyzePacketBody();
    AnalyzePacketFooter();
}

std::unordered_map<std::string, std::string> PacketAnalyzer::getAnalyzedPacket()
{
    return m_analyzedPacket;
}

void PacketAnalyzer::getPacketProtocolType()
{
    std::string packetType = m_packet.substr(PACKET_TYPE_POSITION, PACKET_TYPE_LENGTH);

    if (packetType == eCEPRI_PACKET_TYPE_VALUE)
    {
        m_PacketProtocolType = eCEPRI;
    }
    else
    {
        m_PacketProtocolType = NORMAL;
    }
}

void PacketAnalyzer::getPacketDataLengthAndFCSPosition()
{
    PACKET_DATA_LENGTH = m_packet.length() - PACKET_PREAMBLE_LENGTH - PACKET_DESTINATION_ADDRESS_LENGTH
                                           - PACKET_SOURCE_ADDRESS_LENGTH - PACKET_TYPE_LENGTH - PACKET_FCS_LENGTH;

    PACKET_FCS_POSITION = PACKET_DATA_POSITION + PACKET_DATA_LENGTH;
}

void PacketAnalyzer::AnalyzePacketHeader()
{
    m_analyzedPacket["Preamble"] = m_packet.substr(PACKET_PREAMBLE_POSITION, PACKET_PREAMBLE_LENGTH);
    m_analyzedPacket["Destination Address"] = m_packet.substr(PACKET_DESTINATION_ADDRESS_POSITION, PACKET_DESTINATION_ADDRESS_LENGTH);
    m_analyzedPacket["Source Address"] = m_packet.substr(PACKET_SOURCE_ADDRESS_POSITION, PACKET_SOURCE_ADDRESS_LENGTH);
    m_analyzedPacket["Type"] = m_packet.substr(PACKET_TYPE_POSITION, PACKET_TYPE_LENGTH);
}

void PacketAnalyzer::AnalyzePacketBody()
{
    if (m_PacketProtocolType == eCEPRI)
    {
        AnalyzeeCEPRIPacketBody();
    }
    else
    {
        m_analyzedPacket["Data"] = m_packet.substr(PACKET_DATA_POSITION, PACKET_DATA_LENGTH);
    }
}

void PacketAnalyzer::AnalyzePacketFooter()
{
    m_analyzedPacket["CRC"] = m_packet.substr(PACKET_FCS_POSITION, PACKET_FCS_LENGTH);
}

void PacketAnalyzer::AnalyzeeCEPRIPacketBody()
{
    std::string eCEPRIPacketDataBody = m_packet.substr(PACKET_DATA_POSITION, PACKET_DATA_LENGTH);

    m_analyzedPacket["Message Type"] = eCEPRIPacketDataBody.substr(eCEPRI_PACKET_MESSAGE_TYPE_POSITION, eCEPRI_PACKET_MESSAGE_TYPE_LENGTH);
    m_analyzedPacket["Payload Size"] = eCEPRIPacketDataBody.substr(eCEPRI_PACKET_PAYLOAD_SIZE_POSITION, eCEPRI_PACKET_PAYLOAD_SIZE_LENGTH);
    m_analyzedPacket["RTC ID"] = eCEPRIPacketDataBody.substr(eCEPRI_PACKET_RTC_ID_POSITION, eCEPRI_PACKET_RTC_ID_LENGTH);
    m_analyzedPacket["Sequence ID"] = eCEPRIPacketDataBody.substr(eCEPRI_PACKET_SEQ_ID_POSITION, eCEPRI_PACKET_SEQ_ID_LENGTH);

    char protocolVersion = m_hexToBinaryMap[eCEPRIPacketDataBody[eCEPRI_PACKET_PROTOCOL_VERSION_POSITION]];
    m_analyzedPacket["Protocol Version"] = std::to_string(protocolVersion);

    char ConcatenationIndicator = m_hexToBinaryMap[eCEPRIPacketDataBody[eCEPRI_PACKET_CONCATENATION_INDICATOR_POSITION]];
    m_analyzedPacket["Concatenation Indicator"] = std::to_string(checkConcatenationIndicator(ConcatenationIndicator));


}

bool PacketAnalyzer::checkConcatenationIndicator(char ConcatenationIndicator)
{
    return ((ConcatenationIndicator >> eCEPRI_PACKET_CONCATENATION_INDICATOR_SHIFT_VALUE) & eCEPRI_PACKET_CONCATENATION_INDICATOR_MASK);
}