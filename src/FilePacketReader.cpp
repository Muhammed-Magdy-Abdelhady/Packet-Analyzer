#include "FilePacketReader.hpp"

#include <iostream>

FilePacketReader::FilePacketReader(const std::string &filePath)
    : m_filePath(filePath)
{
    this->open();
}

FilePacketReader::~FilePacketReader()
{
    this->close();
}

// create a move constructor/assigment and do the default behviour and print a message
FilePacketReader::FilePacketReader(FilePacketReader &&other) noexcept
    : m_filePath(std::move(other.m_filePath)), m_fileStream(std::move(other.m_fileStream))
{
    std::cout << "FilePacketReader moved\n";
}

FilePacketReader &FilePacketReader::operator=(FilePacketReader &&other) noexcept
{
    if (this != &other)
    {
        PacketReaderType::operator=(std::move(other));
        this->m_filePath = std::move(other.m_filePath);
        this->m_fileStream = std::move(other.m_fileStream);
        std::cout << "FilePacketReader moved (assignment)\n";
    }
    return *this;
}

bool FilePacketReader::open()
{
    this->m_fileStream.open(this->m_filePath);
    return this->m_fileStream.is_open();
}

void FilePacketReader::close()
{
    if (this->m_fileStream.is_open())
    {
        this->m_fileStream.close();
    }
}

std::vector<std::string> FilePacketReader::readPackets()
{
    std::vector<std::string> packets;
    std::string line;
    while (std::getline(this->m_fileStream, line))
    {
        packets.push_back(line);
    }
    return packets;
}