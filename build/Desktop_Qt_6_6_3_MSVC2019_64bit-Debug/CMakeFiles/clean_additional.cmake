# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SnakeGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SnakeGame_autogen.dir\\ParseCache.txt"
  "SnakeGame_autogen"
  "tests\\CMakeFiles\\SnakeGameTest_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\SnakeGameTest_autogen.dir\\ParseCache.txt"
  "tests\\SnakeGameTest_autogen"
  )
endif()
