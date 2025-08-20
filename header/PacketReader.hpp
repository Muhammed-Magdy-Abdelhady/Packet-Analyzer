#pragma once

#include "PacketReaderType.hpp"
#include <memory>


class PacketReader
{
    std::unique_ptr<PacketReaderType> m_reader;

public:
    PacketReader(std::unique_ptr<PacketReaderType> reader) : m_reader(std::move(reader)) {}

    std::vector<std::string> readPackets();
};