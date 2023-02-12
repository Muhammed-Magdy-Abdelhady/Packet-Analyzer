#pragma once
#include "Packet.h"
#include "eCEPRIPacket.h"
#include "rawPacket.h"
#include <memory>

class PacketAnalyzer
{
public:
    PacketAnalyzer();
    ~PacketAnalyzer();

    std::unique_ptr<Packet> AnalyzePacket(const std::string& packet);
    std::vector<std::unique_ptr<Packet>> AnalyzePackets(const std::vector<std::string>& packets);
    
private:
    Packet::PacketProtocolType getPacketProtocolType(const std::string& packet);
};