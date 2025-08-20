#pragma once

#include "PacketReaderType.hpp"
#include <fstream>

class FilePacketReader : public PacketReaderType
{
public:
    FilePacketReader(const std::string &filePath);
    FilePacketReader(const FilePacketReader &) = delete;
    FilePacketReader(FilePacketReader &&) noexcept;
    FilePacketReader &operator=(const FilePacketReader &) = delete;
    FilePacketReader &operator=(FilePacketReader &&) noexcept;
    ~FilePacketReader();

    std::vector<std::string> readPackets() override;

private:
    bool open() override;
    void close() override;

    std::string m_filePath;
    std::ifstream m_fileStream;
};