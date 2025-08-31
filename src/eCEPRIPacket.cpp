#include "eCEPRIPacket.hpp"
#include <iostream>

void eCEPRIPacket::analyze()
{
    const std::string &x = this->getPacketData();
    std::cout << "Analyzing eCEPRI Packet: " << x << std::endl;
}
