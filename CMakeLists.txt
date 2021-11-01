project(tools LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(sources test/test.cpp)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
add_executable(test ${sources})
target_link_libraries(test gtest_main gtest pthread)
target_include_directories(test PUBLIC include)

