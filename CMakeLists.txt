cmake_minimum_required(VERSION 3.13)
project(AirQualityManagement)

set(CMAKE_CXX_STANDARD 14)

add_executable(AirQualityManagement project/src/main.cpp project/src/airSample.cpp project/src/airSystem.cpp
        project/src/attribute.cpp project/src/sensor.cpp)