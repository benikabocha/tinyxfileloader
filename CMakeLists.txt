cmake_minimum_required(VERSION 3.2)

project(tinyxfileloader)

option(TINYXFILELOADER_ENABLE_TEST "Enable test." on)

set(CMAKE_CXX_STANDARD 14)

if(TINYXFILELOADER_ENABLE_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()

add_executable(example example.cpp tinyxfileloader.h)
