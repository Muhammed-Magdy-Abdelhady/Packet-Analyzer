#pragma once

#include <fstream>
#include <memory>
#include <vector>
#include <unordered_map>


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

    void writePacket(const std::unordered_map<std::string, std::string>& packet);
    void writePackets(const std::vector<std::unordered_map<std::string, std::string>>& packets);

private:
    AnalyzedPacketWriter(fileMode mode = fileMode::OVERWRITE);

    AnalyzedPacketWriter& operator=(const AnalyzedPacketWriter& packet) = delete;

    static std::shared_ptr<AnalyzedPacketWriter> instancePtr;
    std::ofstream writingFile;
    const std::string eCEPRI_TYPE = "AEFE";

    std::vector<std::string> preParedpacketToWrite;
    int packetCounter;

    void preparePacketToWrite(const std::unordered_map<std::string, std::string>& packet);
    void writePacketDelimiter();
};