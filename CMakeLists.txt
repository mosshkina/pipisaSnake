cmake_minimum_required(VERSION 3.16)
project(SnakeGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(Qt6 COMPONENTS Core Gui Widgets Test REQUIRED)

set(SOURCE_FILES
    src/game.cpp
    src/game.h
    src/snake.cpp
    src/snake.h
    src/map.cpp
    src/map.h
    src/obstacle.cpp
    src/obstacle.h
)

set(RESOURCE_FILES
    resources/map1.txt
    resources/map2.txt
    resources/map3.txt
    resources/map4.txt
)

add_executable(SnakeGame main.cpp ${SOURCE_FILES} )

target_link_libraries(SnakeGame Qt6::Core Qt6::Gui Qt6::Widgets)

set_target_properties(SnakeGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_BINARY_DIR}/resources)

install(TARGETS SnakeGame DESTINATION bin)
install(FILES ${RESOURCE_FILES} DESTINATION resources)

enable_testing()
add_subdirectory(tests)
