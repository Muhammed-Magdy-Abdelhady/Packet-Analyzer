#include "FilePacketReader.hpp"
#include "PacketReader.hpp"
#include "AnalyzableWriter.hpp"
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

    // write to file stream, and create a new file if it doesn't exist
    std::ofstream output("packets.txt", std::ios::out | std::ios::trunc);
    if (!output) {
        std::cerr << "Error opening output file.\n";
        return 1;
    }

    for (std::size_t i = 0; i < packets.size(); ++i) {
        const auto& packet = packets[i];
        if (packet != nullptr) {
            output << "Packet # " << i << ":\n";
            output << packet->getPacketData() << "\n";
            AnalyzableWriter::writeAnalyzable(output, *packet);
            output << "\n" << std::string(230, '*') << "\n\n";
        }
    }

    return 0;
}
