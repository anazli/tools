project(tools LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(sources test/test.cpp)
set(RUN_DIR ../test)
set(EXE test)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
add_executable(${EXE} ${sources})
target_link_libraries(${EXE} gtest_main gtest pthread)
target_include_directories(${EXE} PUBLIC include)
set_target_properties(${EXE} PROPERTIES
                       CXX_STANDARD 17
                       RUNTIME_OUTPUT_DIRECTORY ${RUN_DIR})


