#pragma once

#include <fstream>
#include <memory>
#include <vector>
#include "Packet.h"

class AnalyzedPacketWriter
{
public:

    enum fileMode
    {
        OVERWRITE = 0,
        APPEND = 1
    };

    ~AnalyzedPacketWriter();

    AnalyzedPacketWriter(const AnalyzedPacketWriter& packet) = delete;

    static std::shared_ptr<AnalyzedPacketWriter> getInstance(fileMode mode = fileMode::OVERWRITE);

    void writePacket(const std::unique_ptr<Packet>& packet);
    void writePackets(const std::vector<std::unique_ptr<Packet>>& packets);

private:
    AnalyzedPacketWriter(fileMode mode = fileMode::OVERWRITE);

    AnalyzedPacketWriter& operator=(const AnalyzedPacketWriter& packet) = delete;

    static std::shared_ptr<AnalyzedPacketWriter> instancePtr;
    std::ofstream writingFile;

    int packetCounter;

    void writePacketDelimiter();
};