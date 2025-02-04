cmake_minimum_required(VERSION 3.10)
project(PlaybackPipeline)

set(CMAKE_CXX_STANDARD 17)

# Use vcpkg to find installed packages
#find_package(Protobuf REQUIRED)
#find_package(SQLite3 REQUIRED)
#find_package(gRPC REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)


include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/EventProcessor.cpp
    src/StorageManager.cpp
    src/EventGenerator.cpp
    src/EventQueue.cpp
    src/Analytics.cpp
)

# Create executable
add_executable(playback_pipeline ${SOURCES})

# Link against found packages (CMake automatically links them)
target_link_libraries(playback_pipeline  PRIVATE nlohmann_json::nlohmann_json)
