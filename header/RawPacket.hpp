#pragma once

#include "Packet.hpp"

class RawPacket : public Packet {
public:
    RawPacket(std::string packet) : Packet(packet) {}
    virtual ~RawPacket() = default;
    virtual AnalysisResult analyze() const override;
    virtual PacketProtocolType getPacketProtocolType() const override { return PacketProtocolType::NORMAL; };
};