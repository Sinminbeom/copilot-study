cmake_minimum_required(VERSION 3.10)
project(copilot-study)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

# file(GLOB SOURCES "src/*.cpp")
# add_executable(CopilotStudy ${SOURCES})

# add_executable(CopilotStudy "src/main.cpp")

# file(GLOB SOURCES "test/*.cpp")
# add_executable(CopilotStudy ${SOURCES})

# add_executable(CopilotStudy abstractFactoryPattern/test_CameraPropertyFactory.cpp)
add_executable(copilot-study abstractFactoryPattern/CameraPropertyFactory.cpp)

# add_executable(CopilotStudy 
#     src/test_Client.cpp 
#     src/Subscriber.h
#     src/User.cpp
#     src/User.h
#     src/ChatServer.cpp /home/oracle/.vscode-server
#     src/ChatServer.h
# )

# add_executable(CopilotStudy 
#     test/test_SensorFactory.cpp
#     test/SensorFactory.cpp
#     test/LidarFactory.cpp
# )

target_link_libraries(copilot-study pcap gtest)
