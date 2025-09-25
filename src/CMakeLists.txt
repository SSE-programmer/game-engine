file(GLOB_RECURSE GAME_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(GameEngine ${GAME_SRC} ${CMAKE_SOURCE_DIR}/main.cpp)

target_include_directories(GameEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(GameEngine
        PRIVATE
        SSE-engine
)
