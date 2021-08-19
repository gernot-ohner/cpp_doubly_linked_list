//
// Created by gernotohner on 19.08.21.
//

#include "catch.hpp"
#include "../src/DoublyLinkedList.h"

DoublyLinkedList * createSampleList() {
    auto *dll = new DoublyLinkedList{1};
    dll->add(5);
    dll->add(10);
    dll->add(42);
    return dll;
}

TEST_CASE("DLL contains added elements at right indices") {
    // when
    auto dll = *createSampleList();

    // then
    REQUIRE(dll.at(0) == 1);
    REQUIRE(dll.at(1) == 5);
    REQUIRE(dll.at(2) == 10);
    REQUIRE(dll.at(3) == 42);
}


TEST_CASE("DLL throws exception if index is too large") {
    DoublyLinkedList dll{1};
    REQUIRE_THROWS_AS(dll.at(5), std::out_of_range);
}

TEST_CASE("DLL contains inserted elements at right index") {
    // given
    auto dll = *createSampleList();

    // when
    dll.insert(2, 8);

    // then
    REQUIRE(dll.at(0) == 1);
    REQUIRE(dll.at(1) == 5);
    REQUIRE(dll.at(2) == 8);
    REQUIRE(dll.at(3) == 10);
    REQUIRE(dll.at(4) == 42);
}

//TEST_CASE("Can access the first element by calling head()") {
//    auto dll = createSampleList();
//
//
//
//}


// TODO implement this functionality
//TEST_CASE("DLL can delete a node") {
//    // given
//    DoublyLinkedList doublyLinkedList {1};
//    doublyLinkedList.add(5);
//    doublyLinkedList.add(10);
//    doublyLinkedList.add(42);
//
//    // when
//
////    doublyLinkedList.delete(2);
//    int at0 = doublyLinkedList.at(0);
//    int at1 = doublyLinkedList.at(1);
//    int at2 = doublyLinkedList.at(2);
//
//    // then
//    REQUIRE(at0 == 1);
//    REQUIRE(at1 == 5);
//    REQUIRE(at2 == 42);
//}

// TODO add a test testing head()
// TODO add a test testing tail()

TEST_CASE("Can represent the DLL as a string") {
    // given
    auto dll = *createSampleList();
    std::string expected = "[1,5,10,42]";

    // when
    std::string actual = dll.toString();

    // then
    REQUIRE(actual == expected);
}