//
// Created by gernotohner on 19.08.21.
//

#include "catch.hpp"
#include "../src/DoublyLinkedList.h"

DoublyLinkedList<std::string> * createSampleList() {
    auto *dll = new DoublyLinkedList<std::string>{ "oh"};
    dll->add("hey");
    dll->add("there");
    dll->add("friend");
    return dll;
}

TEST_CASE("DLL contains added string elements at right indices") {
    // when
    auto dll = *createSampleList();

    // then
    REQUIRE(dll.at(0) == "oh");
    REQUIRE(dll.at(1) == "hey");
    REQUIRE(dll.at(2) == "there");
    REQUIRE(dll.at(3) == "friend");
}


TEST_CASE("string list: DLL throws exception if index is too large") {
    DoublyLinkedList dll{ "hello world" };
    REQUIRE_THROWS_AS(dll.at(5), std::out_of_range);
}


TEST_CASE("DLL contains inserted string elements at right index") {
    // given
    auto dll = *createSampleList();

    // when
    dll.insert(2, "wow");

    // then
    REQUIRE(dll.at(0) == "oh");
    REQUIRE(dll.at(1) == "hey");
    REQUIRE(dll.at(2) == "wow");
    REQUIRE(dll.at(3) == "there");
    REQUIRE(dll.at(4) == "friend");
}


TEST_CASE("string list: Can access the first element by calling head()") {
    // given
    auto dll = *createSampleList();

    // when
    auto head = dll.head();

    // then
    REQUIRE(head == "oh");
}



TEST_CASE("string list: Can access the last element by calling tail()") {
    // given
    auto dll = *createSampleList();

    // when
    auto head = dll.tail();

    // then
    REQUIRE(head == "friend");
}