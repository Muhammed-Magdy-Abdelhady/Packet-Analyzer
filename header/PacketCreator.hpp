#pragma once

#include "Packet.hpp"
#include <memory>
#include <string>

class PacketCreator
{
public:
    std::unique_ptr<Packet> createPacket(std::string data);
};