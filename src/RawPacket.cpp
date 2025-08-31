#include "RawPacket.hpp"
#include <iostream>

void RawPacket::analyze()
{
    const std::string& x = this->getPacketData();
    std::cout << "Analyzing raw packet: " << x << std::endl;
}
