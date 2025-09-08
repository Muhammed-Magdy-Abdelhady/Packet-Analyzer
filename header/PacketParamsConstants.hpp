struct PacketParams
{
    static constexpr int PACKET_PREAMBLE_POSITION = 0;
    static constexpr int PACKET_PREAMBLE_LENGTH = 16;

    static constexpr int PACKET_DESTINATION_ADDRESS_POSITION = 16;
    static constexpr int PACKET_DESTINATION_ADDRESS_LENGTH = 12;

    static constexpr int PACKET_SOURCE_ADDRESS_POSITION = 28;
    static constexpr int PACKET_SOURCE_ADDRESS_LENGTH = 12;

    static constexpr int PACKET_TYPE_POSITION = 40;
    static constexpr int PACKET_TYPE_LENGTH = 4;

    static constexpr const char* eCEPRI_PACKET_TYPE_VALUE = "AEFE";

    static constexpr int PACKET_DATA_POSITION = 44;

    static constexpr int PACKET_FCS_LENGTH = 8;

    static constexpr int eCEPRI_PACKET_HEADER_POSITION = 0;
    static constexpr int eCEPRI_PACKET_HEADER_LENGTH = 2;

    static constexpr int eCEPRI_PACKET_PROTOCOL_VERSION_POSITION = 0;
    static constexpr int eCEPRI_PACKET_CONCATENATION_INDICATOR_POSITION = 1;

    static constexpr int eCEPRI_PACKET_CONCATENATION_INDICATOR_MASK = 0x8;

    static constexpr int eCEPRI_PACKET_MESSAGE_TYPE_POSITION = 2;
    static constexpr int eCEPRI_PACKET_MESSAGE_TYPE_LENGTH = 2;

    static constexpr int eCEPRI_PACKET_PAYLOAD_SIZE_POSITION = 4;
    static constexpr int eCEPRI_PACKET_PAYLOAD_SIZE_LENGTH = 4;

    static constexpr int eCEPRI_PACKET_RTC_ID_POSITION = 8;
    static constexpr int eCEPRI_PACKET_RTC_ID_LENGTH = 4;

    static constexpr int eCEPRI_PACKET_SEQ_ID_POSITION = 12;
    static constexpr int eCEPRI_PACKET_SEQ_ID_LENGTH = 4;
};
