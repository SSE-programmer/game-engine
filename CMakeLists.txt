cmake_minimum_required(VERSION 3.31)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

# ---- Библиотека SSE-engine ----
file(GLOB_RECURSE SSE_ENGINE_SRC
        ${CMAKE_SOURCE_DIR}/SSE-engine/*.cpp
        ${CMAKE_SOURCE_DIR}/SSE-engine/*.h
)
add_library(SSE-engine STATIC ${SSE_ENGINE_SRC})
target_include_directories(SSE-engine PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(SSE-engine
        PUBLIC
        SFML::System
        SFML::Window
        SFML::Graphics
        SFML::Audio
        SFML::Network
)

# ---- Исполняемый файл (приложение) ----
file(GLOB_RECURSE GAME_SRC
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.h
)
add_executable(GameEngine ${GAME_SRC} main.cpp)
target_include_directories(GameEngine PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(GameEngine
        PRIVATE
        SFML::System
        SFML::Window
        SFML::Graphics
        SFML::Audio
        SFML::Network

        SSE-engine
)