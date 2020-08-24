cmake_minimum_required(VERSION 3.17)
project(SegaMasterSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(SegaMasterSystem src/main.cpp src/SMS_RAM.cpp src/SMS_RAM.hpp src/SMS_Mapper.cpp src/SMS_Mapper.hpp src/SMS_ROM.cpp src/SMS_ROM.hpp src/SMS_Support.hpp)