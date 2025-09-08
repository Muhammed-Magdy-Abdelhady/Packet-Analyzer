cmake_minimum_required(VERSION 3.15)
project(packet_analyzer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set source and header directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(HEADER_DIR "${CMAKE_SOURCE_DIR}/header")
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib")

# Collect all source and header files
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${HEADER_DIR}/*.h" "${HEADER_DIR}/*.hpp")

# Include header directory
include_directories(${HEADER_DIR} ${LIB_DIR}/NumericalTypeConverter)

# Set output directories for different build types
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/build/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/build/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/build/debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build/release)

# build new static library called NumericalTypeConverter
add_subdirectory(${LIB_DIR}/NumericalTypeConverter)

# Create executable
add_executable(packet_analyzer ${SOURCES} ${HEADERS})

# Link NumericalTypeConverter static library
target_link_libraries(packet_analyzer NumericalTypeConverter)

if (WIN32)
	target_link_libraries(packet_analyzer ws2_32)
elseif (UNIX)
	target_link_libraries(packet_analyzer pthread)
endif()