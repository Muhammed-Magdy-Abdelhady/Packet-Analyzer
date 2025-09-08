#pragma once

#include "Packet.hpp"

class eCEPRIPacket : public Packet {
public:
    eCEPRIPacket(std::string packet) : Packet(packet) {}
    virtual ~eCEPRIPacket() = default;
    virtual AnalysisResult analyze() const override;
    virtual PacketProtocolType getPacketProtocolType() const override { return PacketProtocolType::eCEPRI; };
};