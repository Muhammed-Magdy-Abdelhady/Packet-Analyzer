#include "NumericalTypeConverter.h"

#include <sstream>
#include <bitset>

#define INT_SIZE 32

const std::unordered_map<char,char> NumericalTypeConverter::m_hexToBinaryMap  = {
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

int NumericalTypeConverter::hexStringToInt(std::string hexString)
{
    unsigned int value;
    std::stringstream ss;
    ss << std::hex << hexString;
    ss >> value;
    return static_cast<int>(value);
}

int NumericalTypeConverter::octalStringToInt(std::string octalString)
{
    unsigned int value;
    std::stringstream ss;
    ss << std::oct << octalString;
    ss >> value;
    return static_cast<int>(value);
}

int NumericalTypeConverter::binaryStringToInt(std::string binaryString)
{
    unsigned int value;
    std::bitset<INT_SIZE> bitset(binaryString);
    value = bitset.to_ulong();
    return static_cast<int>(value);
}

int NumericalTypeConverter::hexCharToInt(char hexChar)
{
    return m_hexToBinaryMap.at(hexChar);
}


std::string NumericalTypeConverter::intToHexString(int value)
{
    std::stringstream ss;
    ss << std::hex << value;
    return ss.str();
}

std::string NumericalTypeConverter::intToOctalString(int value)
{
    std::stringstream ss;
    ss << std::oct << value;
    return ss.str();
}

std::string NumericalTypeConverter::intToBinaryString(int value)
{
    return std::bitset<INT_SIZE>(value).to_string();
}

std::string NumericalTypeConverter::charToString(char value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}
