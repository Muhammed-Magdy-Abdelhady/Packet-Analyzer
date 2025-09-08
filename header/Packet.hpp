#pragma once

#include <string>
#include "Analyzable.hpp"

class Packet : public Analyzable {
public:
    enum PacketProtocolType {
        NORMAL = 0,
        eCEPRI = 1,
    };

    Packet(std::string packet);
    virtual ~Packet() = default;

    virtual AnalysisResult analyze() const override = 0;
    virtual PacketProtocolType getPacketProtocolType() const = 0;
    std::string getPacketData() const { return m_packet; }

private:
    const std::string m_packet;
    void getPacketDataLengthAndFCSPosition();

protected:
    unsigned char m_packetDataLength;
    unsigned char m_FCSPosition;
};