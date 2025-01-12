cmake_minimum_required(VERSION 3.15)
project(go_game VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)         # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(go_game ${SOURCES})

target_include_directories(go_game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

