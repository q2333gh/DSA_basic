cmake_minimum_required(VERSION 3.21)
project(DSA_impl)

set(CMAKE_CXX_STANDARD 23)

add_executable(DSA_impl main.cpp Vector/Vector.cpp Vector/Vector.h)

#Add the google test subdirectory
add_subdirectory(C:/Code/googletest)

#include googletest/include dir
include_directories(C:/Code/googletest/googletest/include)

#include the googlemock/include dir
include_directories(C:/Code/googletest/googlemock/include)

#Define your executable
add_executable(EXECUTABLE_NAME ${SOURCE_FILES})

#Link with GoogleTest
target_link_libraries(EXECUTABLE_NAME gtest gtest_main)

#Link with GoogleMock
target_link_libraries(EXECUTABLE_NAME gmock gmock_main)