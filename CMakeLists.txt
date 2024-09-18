cmake_minimum_required(VERSION 3.28.2)
set(PROJECT_NAME "REVXT2" CACHE STRING "Project name")
project(${PROJECT_NAME})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out/build)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
# List every subdirectory needed for the build-process here
add_subdirectory(src)

# List custom targets here
add_custom_target(
  launch
    COMMAND $<TARGET_FILE:${PROJECT_NAME}> -h
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running ${PROJECT_NAME} executable"
)

add_custom_target(
  debug
    COMMAND ${CMAKE_DEBUGGER} $<TARGET_FILE:${PROJECT_NAME}>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Debugging ${PROJECT_NAME} executable"
)