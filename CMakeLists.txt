cmake_minimum_required(VERSION 3.28 FATAL_ERROR)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PROJECT_NAME Minecraft_Clone)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME} src/main.cpp)
