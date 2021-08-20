//
// Created by gernotohner on 18.08.21.
//

#include <sstream>
#include "DoublyLinkedList.h"

int DoublyLinkedList::size() const {
    return this->numOfElements;
}

DoublyLinkedList::DoublyLinkedList(std::string value) {
    auto newHeadNode = std::make_shared<Node>(Node{.value = std::make_shared<std::string>(value)});
    this->headNode = newHeadNode;
    this->tailNode = newHeadNode;
    this->numOfElements = 1;
}

void DoublyLinkedList::add(std::string value) {
    auto newNode = std::make_shared<Node>(Node{.value = std::make_shared<std::string>(value)});
    newNode->prev = this->tailNode;
    this->tailNode->next = newNode;
    this->tailNode = newNode;
    this->numOfElements++;
}

std::string DoublyLinkedList::at(int index) {
    if (index >= size()) {
        std::stringstream message;
        message << "Index " << index << " is out of range for list of size " << size() << std::endl;
        throw std::out_of_range(message.str());
    }

    int i = 0;
    auto currentNode = this->headNode;
    while (i < index) {
        currentNode = currentNode->next;
        i++;
    }
    return *currentNode->value;
}

void DoublyLinkedList::insert(int index, std::string value) {
    if (index >= size()-1) add(value);

    int i = 0;
    auto currentNode = headNode;
    while (i < index - 1) {
        currentNode = currentNode->next;
        i++;
    }
    auto newNode = std::make_shared<Node>(
            Node{.value = std::make_shared<std::string>(value)});
    auto nextNode = currentNode->next;

    currentNode->next = newNode;
    newNode->prev = currentNode;
    nextNode->prev = newNode;
    newNode->next = nextNode;

    numOfElements++;
}

std::string DoublyLinkedList::head() {
    return *this->headNode->value;
}

std::string DoublyLinkedList::tail() {
    return *this->tailNode->value;
}

std::string DoublyLinkedList::toString() {
    std::stringstream ss;
    ss << "[";
    auto currentNode = headNode;
    ss << currentNode->value;
    int i = 1;
    while (i < size()) {
        i++;
        currentNode = currentNode->next;
        ss << "," << currentNode->value ;
    }
    ss << "]";
    return ss.str();
}

void DoublyLinkedList::deleteAt(int index) {
    if (index == size() - 1) {
        dropLast();
        return;
    } else if (index > size() - 1) {
        std::stringstream ss;
        ss << "Index " << index << " is out of range for list of size " << size() << std::endl;
        throw std::out_of_range(ss.str());
    }

    int i = 0;
    auto currentNode = headNode;
    while (i < index) {
        currentNode = currentNode->next;
        i++;
    }
    currentNode->prev->next = currentNode->next;
    currentNode->next->prev = currentNode->prev;
}

void DoublyLinkedList::dropLast() {
    tailNode = tailNode->prev;
}

int DoublyLinkedList::find(std::string value) {
    int i = 0;
    int result = -1;
    auto currentNode = headNode;
    do {
        if (*currentNode->value == value) result = i;
        i ++;
        currentNode = currentNode->next;
    } while (currentNode->next);

    return result;
}
