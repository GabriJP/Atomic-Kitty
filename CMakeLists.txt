cmake_minimum_required(VERSION 3.3)
project(Atomic-Kitty)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES Scope.cpp miint.tab.c lex.yy.c Type.cpp MemManager.cpp CodeGeneration.cpp)
SET_SOURCE_FILES_PROPERTIES( miint.tab.c lex.yy.c PROPERTIES LANGUAGE CXX )
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-O0 -Wno-write-strings")

add_custom_target(
        bison ALL
        bison -vdt --debug miint.y && sed -i '/^int yydebug \\= 1\;/d' miint.tab.c
        DEPENDS miint.y
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT Se genera bison
)


add_custom_target(
        flex ALL
        flex milex.l
        DEPENDS milex.l miint.tab.h
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT Se genera flex
)

add_dependencies(${PROJECT_NAME} bison flex)