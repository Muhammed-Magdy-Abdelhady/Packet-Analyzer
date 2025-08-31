#include "FilePacketReader.hpp"
#include "PacketReader.hpp"
#include <memory>
#include <iostream>

// take an argument with the absolute path to the packet file

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <file_path>\n";
        return 1;
    }
    std::cout << "Starting Packet Reader...\n";
    std::string filePath = argv[1];
    std::cout << "Reading packets from file: " << filePath << "\n";

    PacketReader packetReader(std::make_unique<FilePacketReader>(filePath));

    auto packets = packetReader.readPackets();

    for (const auto& packet : packets) {
        if (packet != nullptr) {
            packet->analyze();
        }
    }

    return 0;
}
