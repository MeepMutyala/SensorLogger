cmake_minimum_required(VERSION 3.29)
project(SensorLogger)

set(CMAKE_CXX_STANDARD 14)

add_executable(SensorLogger main.cpp
        code/sensorAPIs/lightSensor.cpp
        code/sensorAPIs/lightSensor.hpp
        code/dataFusion.cpp
        code/dataFusion.hpp
        code/loggerAPIs/realtimeLogger.cpp
        code/loggerAPIs/realtimeLogger.hpp
        code/loggerAPIs/eventLogger.cpp
        code/loggerAPIs/eventLogger.hpp
        code/sensorAPIs/tempSensor.cpp
        code/sensorAPIs/tempSensor.hpp)

find_package(Threads REQUIRED)

target_link_libraries(SensorLogger PRIVATE Threads::Threads)
