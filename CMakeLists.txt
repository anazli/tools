project(tools LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(sources test/test.cpp)
set(RUN_DIR ../test)
set(EXE test-cases)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
add_executable(${EXE} ${sources})
target_link_libraries(${EXE} gtest_main gtest pthread)
target_include_directories(${EXE} PUBLIC include)
set_target_properties(${EXE} PROPERTIES
                       RUNTIME_OUTPUT_DIRECTORY ${RUN_DIR})

