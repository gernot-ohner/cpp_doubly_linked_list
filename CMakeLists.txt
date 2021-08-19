cmake_minimum_required(VERSION 3.20)
project(doubly_linked_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(doubly_linked_list main.cpp src/DoublyLinkedList.cpp src/DoublyLinkedList.h)
add_executable(doubly_linked_list_tests
        src/DoublyLinkedList.cpp
        src/DoublyLinkedList.h
        test/test.cpp
        test/catch.hpp
        test/DoublyLinkedListTest.cpp
        )

