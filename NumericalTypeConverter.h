#pragma once

#include <string>
#include <unordered_map>

class NumericalTypeConverter
{
public:
    static int hexStringToInt(std::string hexString);
    static int octalStringToInt(std::string octalString);
    static int binaryStringToInt(std::string binaryString);
    static int hexCharToInt(char hexChar);
    
    static std::string intToHexString(int value);
    static std::string intToOctalString(int value);
    static std::string intToBinaryString(int value);
    static std::string charToString(char value);

private:
    static const std::unordered_map<char,char> m_hexToBinaryMap;
};