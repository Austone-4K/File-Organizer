cmake_minimum_required(VERSION 3.10)

project(File-Organizer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/exe)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")

add_executable(File-Organizer source/file-organizer.cpp)

target_link_options(File-Organizer PRIVATE "-static")