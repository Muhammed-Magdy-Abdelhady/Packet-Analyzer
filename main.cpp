#include "PacketReader.h"
#include "AnalyzedPacketWriter.h"
#include "PacketAnalyzer.h"

int main() {
    
    std::shared_ptr<PacketReader> packetReader = PacketReader::getInstance();
    std::shared_ptr<AnalyzedPacketWriter> AnalyzedPacketWriter = AnalyzedPacketWriter::getInstance();

    std::vector<std::string> packets = packetReader->readPackets();
    PacketAnalyzer packetAnalyzer;
    
    std::vector<std::unique_ptr<Packet>> analyzedPackets = packetAnalyzer.AnalyzePackets(packets);
    AnalyzedPacketWriter->writePackets(analyzedPackets);

    return 0;
}