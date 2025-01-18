cmake_minimum_required(VERSION 3.15)
project(go_game VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)         # Use C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SDL2_DIR "/opt/homebrew/Cellar/sdl2/2.30.11/lib/cmake/SDL2")
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

add_executable(go_game ${SOURCES})

target_include_directories(go_game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(go_game PRIVATE
    SDL2::SDL2
)

