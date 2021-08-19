//
// Created by gernotohner on 19.08.21.
//

#include "catch.hpp"
#include "../src/DoublyLinkedList.h"

TEST_CASE("DLL contains added elements at right indices") {
    // given
    DoublyLinkedList doublyLinkedList {1};
    doublyLinkedList.add(5);
    doublyLinkedList.add(10);
    doublyLinkedList.add(42);

    // when
    int at0 = doublyLinkedList.at(0);
    int at1 = doublyLinkedList.at(1);
    int at2 = doublyLinkedList.at(2);
    int at3 = doublyLinkedList.at(3);

    // then
    REQUIRE(at0 == 1);
    REQUIRE(at1 == 5);
    REQUIRE(at2 == 10);
    REQUIRE(at3 == 42);
}


TEST_CASE("DLL throws exception if index is too large") {

    DoublyLinkedList dll {1};

    REQUIRE_THROWS_AS(dll.at(5), std::out_of_range);
}

TEST_CASE("DLL contains inserted elements at right index") {
    // given
    DoublyLinkedList doublyLinkedList {1};
    doublyLinkedList.add(5);
    doublyLinkedList.add(10);
    doublyLinkedList.add(42);

    // when

    // insert now in
    doublyLinkedList.insert(2, 8);
    int at0 = doublyLinkedList.at(0);
    int at1 = doublyLinkedList.at(1);
    int at2 = doublyLinkedList.at(2);
    int at3 = doublyLinkedList.at(3);
    int at4 = doublyLinkedList.at(4);

    // then
    REQUIRE(at0 == 1);
    REQUIRE(at1 == 5);
    REQUIRE(at2 == 8);
    REQUIRE(at3 == 10);
    REQUIRE(at4 == 42);
}


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
