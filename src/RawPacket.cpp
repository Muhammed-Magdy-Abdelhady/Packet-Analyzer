#include "RawPacket.hpp"
#include "PacketParamsConstants.hpp"
#include <iostream>

AnalysisResult RawPacket::analyze() const
{
    AnalysisResult result;

    const std::string& packetData = this->getPacketData();

    std::string eCEPRIPacketDataBody = packetData.substr(PacketParams::PACKET_DATA_POSITION, this->m_packetDataLength);

    result.emplace_back("CRC", packetData.substr(this->m_FCSPosition, PacketParams::PACKET_FCS_LENGTH));
    result.emplace_back("Destination Address", packetData.substr(PacketParams::PACKET_DESTINATION_ADDRESS_POSITION, PacketParams::PACKET_DESTINATION_ADDRESS_LENGTH));
    result.emplace_back("Source Address", packetData.substr(PacketParams::PACKET_SOURCE_ADDRESS_POSITION, PacketParams::PACKET_SOURCE_ADDRESS_LENGTH));
    result.emplace_back("Type", packetData.substr(PacketParams::PACKET_TYPE_POSITION, PacketParams::PACKET_TYPE_LENGTH));

    return result;
}
