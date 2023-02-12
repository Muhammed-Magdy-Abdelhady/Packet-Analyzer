#include "AnalyzedPacketWriter.h"

#define WRITE_FILE_NAME "analyzedPackets.txt"
#define PACKET_DELIMITER_NUMBER 230

std::shared_ptr<AnalyzedPacketWriter> AnalyzedPacketWriter::instancePtr = nullptr;

std::shared_ptr<AnalyzedPacketWriter> AnalyzedPacketWriter::getInstance(fileMode mode)
{
    //make a shared pointer to the instance
    if (instancePtr == nullptr)
    {
        instancePtr = std::shared_ptr<AnalyzedPacketWriter>(new AnalyzedPacketWriter(mode));
    }

    return instancePtr;
}

AnalyzedPacketWriter::AnalyzedPacketWriter(fileMode mode)
{
    if (mode == fileMode::OVERWRITE)
    {
        writingFile.open(WRITE_FILE_NAME, std::ios::trunc);
    }
    else
    {
        writingFile.open(WRITE_FILE_NAME, std::ios::app);
    }

    packetCounter = 0;
}

AnalyzedPacketWriter::~AnalyzedPacketWriter()
{
    writingFile.close();
}

void AnalyzedPacketWriter::writePacket(const std::unique_ptr<Packet>& packet)
{
    auto preParedpacketToWrite = packet->breakDownPacket();


    writingFile << "Packet # " << packetCounter << ":" << std::endl;
    for (const auto& mem : preParedpacketToWrite)
    {
        writingFile << mem << std::endl;
    }

    writePacketDelimiter();
}

void AnalyzedPacketWriter::writePackets(const std::vector<std::unique_ptr<Packet>>& packets)
{
    for (const auto& packet : packets)
    {
        writePacket(packet);
    }
}

void AnalyzedPacketWriter::writePacketDelimiter()
{
    writingFile << std::endl << std::string(PACKET_DELIMITER_NUMBER,'*') << std::endl << std::endl;
    ++packetCounter;
}
    