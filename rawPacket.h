#include "Packet.h"

class rawPacket : public Packet
{
public:
    rawPacket(const std::string& packet);
    ~rawPacket();

    std::vector<std::string> breakDownPacket();
    PacketProtocolType getPacketType();
private:
    const std::string m_packet;
    PacketProtocolType m_packetType;
    void getPacketDataLengthAndFCSPosition();

    unsigned char PACKET_DATA_LENGTH;
    unsigned char PACKET_FCS_POSITION;
};