cmake_minimum_required(VERSION 3.0.0)
project(doonoon VERSION 0.1.0 LANGUAGES C CXX)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(doonoon main.cpp Game.h CScene.cpp CScene.h CSnake.cpp CSnake.h CMap.h CMap.cpp CMapBuilder.h CMapBuilder.cpp CItems.h CItems.cpp)
target_link_libraries(doonoon ${CURSES_LIBRARIES})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
