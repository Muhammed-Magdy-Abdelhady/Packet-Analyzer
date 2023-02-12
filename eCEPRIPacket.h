#include "Packet.h"

class eCEPRIPacket : public Packet
{
public:
    eCEPRIPacket(const std::string& packet);
    ~eCEPRIPacket();

    std::vector<std::string> breakDownPacket();
    PacketProtocolType getPacketType();
private:
    const std::string m_packet;
    PacketProtocolType m_packetType;
    void getPacketDataLengthAndFCSPosition();
    bool checkConcatenationIndicator(int concatenationIndicator);

    unsigned char PACKET_DATA_LENGTH;
    unsigned char PACKET_FCS_POSITION;
};