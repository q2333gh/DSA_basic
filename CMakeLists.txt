cmake_minimum_required(VERSION 3.21)
project(DSA_impl)

set(CMAKE_CXX_STANDARD 23)

add_executable(DSA_impl main.cpp Vector/Vector.cpp List/ListNode.cpp)

# 添加头文件
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest/include
)

# 添加下级目录，生成.a文件
add_subdirectory( ./googletest)

# 添加连接库
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

set(SOUCE_FLIES
        main.cpp
        Vector/Vector.cpp
        List/ListNode.cpp
        List/List.cpp)

# 指定可执行文件的生成位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# 指定生成目标
add_executable(TestAdd ${SOUCE_FLIES})

# 将目标文件与库文件进行链接
target_link_libraries(DSA_impl gtest)


##Add the google test subdirectory
#add_subdirectory(C:/Code/googletest)
#
##include googletest/include dir
#include_directories(C:/Code/googletest/googletest/include)
#
##include the googlemock/include dir
#include_directories(C:/Code/googletest/googlemock/include)
#
##Define your executable
#add_executable(EXECUTABLE_NAME ${SOURCE_FILES})
#
##Link with GoogleTest
#target_link_libraries(EXECUTABLE_NAME gtest gtest_main)
#
##Link with GoogleMock
#target_link_libraries(EXECUTABLE_NAME gmock gmock_main)