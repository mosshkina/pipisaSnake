set(SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/game.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/snake.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/snake.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/map.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/map.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/obstacle.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/obstacle.h
)

set(TEST_SOURCES
    snakegametest.h
    snakegametest.cpp
)

add_executable(SnakeGameTest ${TEST_SOURCES} ${SOURCE_FILES})
target_link_libraries(SnakeGameTest Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Test)
install(TARGETS SnakeGameTest DESTINATION tests)
add_test(NAME SnakeGameTest COMMAND SnakeGameTest)
