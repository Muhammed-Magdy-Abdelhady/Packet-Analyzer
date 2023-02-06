#pragma once

#include <string>
#include <vector>
#include <unordered_map>


class PacketAnalyzer
{
public:
    PacketAnalyzer(const std::string& packet);
    ~PacketAnalyzer();

    void AnalyzePacket();
    std::unordered_map<std::string, std::string> getAnalyzedPacket();
private:
    enum PacketProtocolType
    {
        NORMAL = 0,
        eCEPRI = 1
    };

    PacketProtocolType m_PacketProtocolType;
    const std::string& m_packet;
    std::unordered_map<std::string, std::string> m_analyzedPacket;

    unsigned char PACKET_DATA_LENGTH;

    unsigned char PACKET_FCS_POSITION;

    std::unordered_map<char,char> m_hexToBinaryMap = {
        {'0', 0b0000},
        {'1', 0b0001},
        {'2', 0b0010},
        {'3', 0b0011},
        {'4', 0b0100},
        {'5', 0b0101},
        {'6', 0b0110},
        {'7', 0b0111},
        {'8', 0b1000},
        {'9', 0b1001},
        {'A', 0b1010},
        {'B', 0b1011},
        {'C', 0b1100},
        {'D', 0b1101},
        {'E', 0b1110},
        {'F', 0b1111}
    }; 


    void getPacketProtocolType();
    void getPacketDataLengthAndFCSPosition();
    void AnalyzeeCEPRIPacketBody();
    void AnalyzePacketHeader();
    void AnalyzePacketBody();
    void AnalyzePacketFooter();
    static inline bool checkConcatenationIndicator(char concatenationIndicator);
};