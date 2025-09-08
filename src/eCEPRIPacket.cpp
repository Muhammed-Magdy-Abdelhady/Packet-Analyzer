#include "eCEPRIPacket.hpp"
#include "NumericalTypeConverter.hpp"
#include "PacketParamsConstants.hpp"
#include <iostream>

AnalysisResult eCEPRIPacket::analyze() const
{
    AnalysisResult result;
    // Perform analysis and populate result
    const auto& packet_data = this->getPacketData();
    std::string eCEPRIPacketDataBody = packet_data.substr(PacketParams::PACKET_DATA_POSITION, this->m_packetDataLength);

    int protocolVersion = NumericalTypeConverter::hexCharToInt(
        eCEPRIPacketDataBody[PacketParams::eCEPRI_PACKET_PROTOCOL_VERSION_POSITION]
    );

    int concatenationIndicator = NumericalTypeConverter::hexCharToInt(
        eCEPRIPacketDataBody[PacketParams::eCEPRI_PACKET_CONCATENATION_INDICATOR_POSITION]
    );

    result.emplace_back("CRC", packet_data.substr(this->m_FCSPosition, PacketParams::PACKET_FCS_LENGTH));
    result.emplace_back("Concatenation Indicator", std::to_string(concatenationIndicator));
    result.emplace_back("Destination Address", packet_data.substr(PacketParams::PACKET_DESTINATION_ADDRESS_POSITION, PacketParams::PACKET_DESTINATION_ADDRESS_LENGTH));
    result.emplace_back("Message Type", eCEPRIPacketDataBody.substr(PacketParams::eCEPRI_PACKET_MESSAGE_TYPE_POSITION, PacketParams::eCEPRI_PACKET_MESSAGE_TYPE_LENGTH));
    result.emplace_back("Payload Size", eCEPRIPacketDataBody.substr(PacketParams::eCEPRI_PACKET_PAYLOAD_SIZE_POSITION, PacketParams::eCEPRI_PACKET_PAYLOAD_SIZE_LENGTH));
    result.emplace_back("Protocol Version", std::to_string(protocolVersion));
    result.emplace_back("RTC ID", eCEPRIPacketDataBody.substr(PacketParams::eCEPRI_PACKET_RTC_ID_POSITION, PacketParams::eCEPRI_PACKET_RTC_ID_LENGTH));
    result.emplace_back("Sequence ID", eCEPRIPacketDataBody.substr(PacketParams::eCEPRI_PACKET_SEQ_ID_POSITION, PacketParams::eCEPRI_PACKET_SEQ_ID_LENGTH));
    result.emplace_back("Source Address", packet_data.substr(PacketParams::PACKET_SOURCE_ADDRESS_POSITION, PacketParams::PACKET_SOURCE_ADDRESS_LENGTH));
    result.emplace_back("Type", packet_data.substr(PacketParams::PACKET_TYPE_POSITION, PacketParams::PACKET_TYPE_LENGTH));

    return result;
}