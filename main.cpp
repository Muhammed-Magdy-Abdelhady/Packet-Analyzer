#include "PacketReader.h"
#include "AnalyzedPacketWriter.h"
#include "PacketAnalyzer.h"
#include <iostream>
#include <string>

int main() {
    
    std::shared_ptr<PacketReader> packetReader = PacketReader::getInstance();
    std::shared_ptr<AnalyzedPacketWriter> AnalyzedPacketWriter = AnalyzedPacketWriter::getInstance();

    std::vector<std::string> packets = packetReader->readPackets();

    for (const auto& packet : packets)
    {
        PacketAnalyzer packetAnalyzer = PacketAnalyzer(packet);
        packetAnalyzer.AnalyzePacket();
        std::unordered_map<std::string, std::string> analyzedPacket = packetAnalyzer.getAnalyzedPacket();
        AnalyzedPacketWriter->writePacket(analyzedPacket);
    }


    return 0;
}