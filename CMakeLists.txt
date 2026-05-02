cmake_minimum_required(VERSION 3.29)
project(StoneMath)

set(CMAKE_CXX_STANDARD 20)


add_library(StoneMath STATIC
        src/Lexer.cpp
        src/Parser.cpp
        src/Evaluator.cpp
        src/StoneMath.cpp
)

target_include_directories(StoneMath PUBLIC include)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(StoneMath_Tests tests/main.cpp)
    target_link_libraries(StoneMath_Tests PRIVATE StoneMath)
endif()