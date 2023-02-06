#pragma once

#include <fstream>
#include <memory>
#include <vector>

/*
    deleted the copy constructor and assignment operator to prevent the class from being copied and
    deleted the default constructor to prevent the class from being instantiated

*/

class PacketReader
{
public:
    ~PacketReader();

    PacketReader(const PacketReader& packet) = delete;

    static std::shared_ptr<PacketReader> getInstance();

    std::string readPacket();
    std::vector<std::string> readPackets();

private:
    PacketReader();

    PacketReader& operator=(const PacketReader& packet) = delete;

    static std::shared_ptr<PacketReader> instancePtr;
    std::ifstream readingFile;
};