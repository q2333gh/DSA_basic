cmake_minimum_required(VERSION 3.21)
project(DSA_new)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        DSA_new main.cpp
        List/List.cpp
        List/ListNode.cpp
        Stack/Stack.cpp
        Vector/Vector.cpp
        _test/test1.cpp _test/test1.h)

