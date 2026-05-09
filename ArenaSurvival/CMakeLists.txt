cmake_minimum_required(VERSION 3.10)

project(ArenaSurvival)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 3.0 REQUIRED COMPONENTS
    Graphics
    Window
    System
    Audio
    Network
)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(ArenaSurvival ${SOURCES})

target_include_directories(ArenaSurvival PRIVATE include)

target_link_libraries(ArenaSurvival PRIVATE
    SFML::Graphics 
    SFML::Window 
    SFML::System 
    SFML::Audio 
    SFML::Network
)