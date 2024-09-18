cmake_minimum_required(VERSION 3.28.2)
set(PROJECT_NAME "REVXT2")
set(TEST_NAME "REVXT2_TEST")
project(${PROJECT_NAME})

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out/build)

# Main Client executable
add_executable(${PROJECT_NAME} main.cpp)

# Main Test executable setup
include(CTest)
add_executable(${TEST_NAME} test/moveUtils_test.cpp)
add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
)

include_directories(${PROJECT_SOURCE_DIR}/include)


# List every subdirectory needed for the build-process here
add_subdirectory(src)
add_subdirectory(test)



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