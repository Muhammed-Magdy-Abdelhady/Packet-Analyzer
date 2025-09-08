add_library(NumericalTypeConverter STATIC
    NumericalTypeConverter.cpp
    NumericalTypeConverter.hpp
)

target_include_directories(NumericalTypeConverter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})