#pragma once 

#define PACKET_PREAMBLE_POSITION  0
#define PACKET_PREAMBLE_LENGTH  16

#define PACKET_DESTINATION_ADDRESS_POSITION  16
#define PACKET_DESTINATION_ADDRESS_LENGTH  12

#define PACKET_SOURCE_ADDRESS_POSITION  28
#define PACKET_SOURCE_ADDRESS_LENGTH  12

#define PACKET_TYPE_POSITION  40
#define PACKET_TYPE_LENGTH  4

#define eCEPRI_PACKET_TYPE_VALUE  "AEFE"

#define PACKET_DATA_POSITION  44

#define PACKET_FCS_LENGTH  8 

#define eCEPRI_PACKET_HEADER_POSITION  0
#define eCEPRI_PACKET_HEADER_LENGTH  2

#define eCEPRI_PACKET_PROTOCOL_VERSION_POSITION  0
#define eCEPRI_PACKET_CONCATENATION_INDICATOR_POSITION  1
#define eCEPRI_PACKET_CONCATENATION_INDICATOR_SHIFT_VALUE  3

#define eCEPRI_PACKET_CONCATENATION_INDICATOR_MASK  0x1

#define eCEPRI_PACKET_MESSAGE_TYPE_POSITION  2
#define eCEPRI_PACKET_MESSAGE_TYPE_LENGTH  2

#define eCEPRI_PACKET_PAYLOAD_SIZE_POSITION  4
#define eCEPRI_PACKET_PAYLOAD_SIZE_LENGTH  4

#define eCEPRI_PACKET_RTC_ID_POSITION  8
#define eCEPRI_PACKET_RTC_ID_LENGTH  4

#define eCEPRI_PACKET_SEQ_ID_POSITION  12
#define eCEPRI_PACKET_SEQ_ID_LENGTH  4