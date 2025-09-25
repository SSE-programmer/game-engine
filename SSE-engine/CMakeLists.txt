file(GLOB_RECURSE SSE_ENGINE_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
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
