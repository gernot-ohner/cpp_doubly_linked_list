//
// Created by gernotohner on 18.08.21.
//

#include <sstream>
#include "DoublyLinkedList.h"

int DoublyLinkedList::size() const {
    return this->numOfElements;
}

DoublyLinkedList::DoublyLinkedList(int value) {
    Node *newHeadNode = new Node{.value = value};
    this->headNode = newHeadNode;
    this->tailNode = newHeadNode;
    this->numOfElements = 1;
}

void DoublyLinkedList::add(int value) {
    Node *newNode = new Node{.value = value};
    newNode->prev = this->tailNode;
    this->tailNode->next = newNode;
    this->tailNode = newNode;
    this->numOfElements++;
}

int DoublyLinkedList::at(int index) {
    if (index >= size()) {
        std::stringstream message;
        message << "Index " << index << " is out of range for list of size " << size() << std::endl;
        throw std::out_of_range(message.str());
    }

    int i = 0;
    Node *currentNode = this->headNode;
    while (i < index) {
        currentNode = currentNode->next;
        i++;
    }
    return currentNode->value;
}

void DoublyLinkedList::insert(int index, int value) {
    if (index >= size()-1) add(value);

    int i = 0;
    Node *currentNode = headNode;
    while (i < index - 1) {
        currentNode = currentNode->next;
        i++;
    }
    Node *newNode = new Node{.value = value};
    Node *nextNode = currentNode->next;

    currentNode->next = newNode;
    newNode->prev = currentNode;
    nextNode->prev = newNode;
    newNode->next = nextNode;

    numOfElements++;
}

int DoublyLinkedList::head() {
    return this->headNode->value;
}

int DoublyLinkedList::tail() {
    return this->tailNode->value;
}

std::string DoublyLinkedList::toString() {
    std::stringstream ss;
    ss << "[";
    Node* currentNode = headNode;
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
    Node* currentNode = headNode;
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
