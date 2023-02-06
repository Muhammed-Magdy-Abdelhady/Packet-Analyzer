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

void AnalyzedPacketWriter::writePacket(const std::unordered_map<std::string, std::string>& packet)
{
    preparePacketToWrite(packet);

    for (const auto& mem : preParedpacketToWrite)
    {
        writingFile << mem << std::endl;
    }

    writePacketDelimiter();
}

void AnalyzedPacketWriter::writePackets(const std::vector<std::unordered_map<std::string, std::string>>& packets)
{
    for (const auto& packet : packets)
    {
        writePacket(packet);
    }
}

void AnalyzedPacketWriter::preparePacketToWrite(const std::unordered_map<std::string, std::string>& packet)
{

    preParedpacketToWrite.clear();
    preParedpacketToWrite.push_back("Packet # " + std::to_string(packetCounter) +":");
    preParedpacketToWrite.push_back(packet.at("Whole Packet"));
    preParedpacketToWrite.push_back("CRC: " + packet.at("CRC"));

    if (packet.at("Type") == eCEPRI_TYPE){
        preParedpacketToWrite.push_back("Concatenation Indicator: " + packet.at("Concatenation Indicator"));
    }

    preParedpacketToWrite.push_back("Destination Address: " + packet.at("Destination Address"));
    
    if (packet.at("Type") == eCEPRI_TYPE){
        preParedpacketToWrite.push_back("Message Type: " + packet.at("Message Type"));
        preParedpacketToWrite.push_back("Payload Size: " + packet.at("Payload Size"));
        preParedpacketToWrite.push_back("Protocol Version: " + packet.at("Protocol Version"));
        preParedpacketToWrite.push_back("RTC ID: " + packet.at("RTC ID"));
        preParedpacketToWrite.push_back("Sequence ID: " + packet.at("Sequence ID"));
    }

    preParedpacketToWrite.push_back("Source Address: " + packet.at("Source Address"));
    preParedpacketToWrite.push_back("Type: " + packet.at("Type"));

    ++packetCounter;
}

void AnalyzedPacketWriter::writePacketDelimiter()
{
    writingFile << std::endl << std::string(PACKET_DELIMITER_NUMBER,'*') << std::endl << std::endl;
}
    