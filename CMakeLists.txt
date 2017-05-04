cmake_minimum_required(VERSION 3.6)
project(Atomik-Kitty)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES Scope.cpp miint.tab.c lex.yy.c Type.cpp MemManager.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-O3 -Wno-write-strings")
set(CMAKE_C_FLAGS "-O3 -Wno-write-strings")
set(CMAKE_C_COMPILER /usr/bin/c++)
