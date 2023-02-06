#include "PacketReader.h"

#define PACKET_FILE_NAME "input_packets"

std::shared_ptr<PacketReader> PacketReader::instancePtr = nullptr;

std::shared_ptr<PacketReader> PacketReader::getInstance()
{
    //make a shared pointer to the instance
    if (instancePtr == nullptr)
    {
        instancePtr = std::shared_ptr<PacketReader>(new PacketReader());
    }

    return instancePtr; 
}

PacketReader::PacketReader()
{
    readingFile.open(PACKET_FILE_NAME);

    if (!readingFile.is_open())
    {
        throw std::invalid_argument("File not found OR file is corrupted");
    }
}

PacketReader::~PacketReader()
{
    readingFile.close();
}

std::string PacketReader::readPacket()
{
    std::string packet;

    std::getline(readingFile, packet);
    
    return packet;
}

std::vector<std::string> PacketReader::readPackets()
{
    std::vector<std::string> packets;

    std::string packet;

    while (std::getline(readingFile, packet))
    {
        packets.push_back(packet);
    }

    return packets;
}