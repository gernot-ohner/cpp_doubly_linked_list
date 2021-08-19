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

TEST_CASE("Can access the first element by calling head()") {
    // given
    auto dll = *createSampleList();

    // when
    auto head = dll.head();

    // then
    REQUIRE(head == 1);
}

TEST_CASE("Can access the first element by calling tail()") {
    // given
    auto dll = *createSampleList();

    // when
    auto head = dll.tail();

    // then
    REQUIRE(head == 42);
}

TEST_CASE("Can access the first element by calling tail() after inserting") {
    // given
    auto dll = *createSampleList();

    // when
    dll.insert(2, 8);

    // then
    REQUIRE(dll.tail() == 42);
}

TEST_CASE("Can access the first element by calling tail() after inserting at last position") {
    // given
    auto dll = *createSampleList();

    // when
    dll.insert(dll.size() - 1, 8);

    // then
    REQUIRE(dll.tail() == 8);
}

TEST_CASE("DLL can delete a node") {
    // given
    auto dll = *createSampleList();

    // when
    dll.deleteAt(2);

    // then
    REQUIRE(dll.at(0) == 1);
    REQUIRE(dll.at(1) == 5);
    REQUIRE(dll.at(2) == 42);
}

TEST_CASE("DLL can delete the last node") {
    // given
    auto dll = *createSampleList();

    // when
    dll.deleteAt(3);

    // then
    REQUIRE(dll.at(0) == 1);
    REQUIRE(dll.at(1) == 5);
    REQUIRE(dll.at(2) == 10);
}

TEST_CASE("Exception is thrown if index to delete is too large") {
    // given
    auto dll = *createSampleList();

    // when
    // then
    REQUIRE_THROWS_AS(dll.deleteAt(5), std::out_of_range);
}

TEST_CASE("Can represent the DLL as a string") {
    // given
    auto dll = *createSampleList();
    std::string expected = "[1,5,10,42]";

    // when
    std::string actual = dll.toString();

    // then
    REQUIRE(actual == expected);
}