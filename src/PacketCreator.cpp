#include "PacketCreator.hpp"
#include "PacketParamsConstants.hpp"
#include "RawPacket.hpp"
#include "eCEPRIPacket.hpp"

std::unique_ptr<Packet> PacketCreator::createPacket(std::string data)
{
    std::string packetType = data.substr(
        PacketParams::PACKET_TYPE_POSITION,
        PacketParams::PACKET_TYPE_LENGTH
    );

    if (packetType == PacketParams::eCEPRI_PACKET_TYPE_VALUE) {
        return std::make_unique<eCEPRIPacket>(data);
    } else {
        return std::make_unique<RawPacket>(data);
    }

    return nullptr;
}