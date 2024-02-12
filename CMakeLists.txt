cmake_minimum_required(VERSION 3.10)
project(copilot-study)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

# file(GLOB SOURCES "src/*.cpp")
# add_executable(copilot-study ${SOURCES})

# add_executable(copilot-study "src/main.cpp")

# file(GLOB SOURCES "test/*.cpp")
# add_executable(copilot-study ${SOURCES})

# add_executable(copilot-study abstractFactoryPattern/test_CameraPropertyFactory.cpp)
add_executable(copilot-study abstractFactoryPattern/test_CameraPropertyFactory.cpp)

# add_executable(copilot-study 
#     src/test_Client.cpp 
#     src/Subscriber.h
#     src/User.cpp
#     src/User.h
#     src/ChatServer.cpp /home/oracle/.vscode-server
#     src/ChatServer.h
# )

# add_executable(copilot-study 
#     test/test_SensorFactory.cpp
#     test/SensorFactory.cpp
#     test/LidarFactory.cpp
# )

target_link_libraries(copilot-study pcap gtest)
