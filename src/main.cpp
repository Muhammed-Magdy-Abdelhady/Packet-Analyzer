#include "SocketPacketReader.hpp"
#include "PacketReader.hpp"
#include <memory>
#include <iostream>

// take an argument with the absolute path to the packet file

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <port>\n";
        return 1;
    }
    std::cout << "Starting Packet Reader...\n";
    int port = std::stoi(argv[1]);
    std::cout << "Reading packets from port: " << port << "\n";

    PacketReader packetReader(std::make_unique<SocketPacketReader>(port));

    auto packets = packetReader.readPackets();

    for (const auto &packet : packets)
    {
        std::cout << packet << "\n";
    }

    return 0;
}
