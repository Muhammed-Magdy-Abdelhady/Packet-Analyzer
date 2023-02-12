#pragma once
#include <vector>
#include <string>



class Packet{
public:
    enum PacketProtocolType
    {
        NORMAL = 0,
        eCEPRI = 1
    };

    virtual std::vector<std::string> breakDownPacket() = 0;
    virtual PacketProtocolType getPacketType() = 0;
private:
    virtual void getPacketDataLengthAndFCSPosition() = 0;


};