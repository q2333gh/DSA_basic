cmake_minimum_required(VERSION 3.21)
project(DSA_new)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        DSA_new main.cpp
        List/List.h
        List/ListNode.h
        Stack_via_Vector/Stack.h
        Vector/Vector.h
         Stack_app/cast.h)

