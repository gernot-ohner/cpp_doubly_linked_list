//
// Created by gernotohner on 18.08.21.
//

#ifndef PLAYGROUND_DOUBLYLINKEDLIST_H
#define PLAYGROUND_DOUBLYLINKEDLIST_H

#include <memory>
#include <vector>
#include <string>
#include <sstream>

template<typename T>
struct Node {
    std::shared_ptr<T> value;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
};

template<typename T>
class DoublyLinkedList {
public:

    // TODO Add constructor to create empty list
    explicit DoublyLinkedList(T value) {
        auto newHeadNode = std::make_shared<Node<T>>(Node<T>{.value = std::make_shared<T>(value)});
        this->headNode = newHeadNode;
        this->tailNode = newHeadNode;
        this->numOfElements = 1;
    }

    [[nodiscard]] int size() const { return numOfElements; }

    T at(int index) {
        if (index >= size()) {
            std::stringstream message;
            message << "Index ";
            message << index ;
            message << " is out of range for list of size " ;
            message << size() ;
            message << std::endl;
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

    T head() { return *this->headNode->value; }

    T tail() { return *this->tailNode->value; }

    void insert(int index, T value) {
        if (index >= size() - 1) add(value);

        int i = 0;
        auto currentNode = headNode;
        while (i < index - 1) {
            currentNode = currentNode->next;
            i++;
        }
        auto newNode = std::make_shared<Node<T>>(
                Node<T>{.value = std::make_shared<T>(value)});
        auto nextNode = currentNode->next;

        currentNode->next = newNode;
        newNode->prev = currentNode;
        nextNode->prev = newNode;
        newNode->next = nextNode;

        numOfElements++;
    }

    void add(T value) {
        auto newNode = std::make_shared<Node<T>>(Node<T>{.value = std::make_shared<T>(value)});
        newNode->prev = this->tailNode;
        this->tailNode->next = newNode;
        this->tailNode = newNode;
        this->numOfElements++;
    }

    // TODO ensure that this method works if the list is empty. Currently a segfault?
    [[nodiscard]] std::string toString() const {
        std::stringstream ss;
        ss << "[";
        auto currentNode = headNode;
        ss << *currentNode->value;
        int i = 1;
        while (i < size()) {
            i++;
            currentNode = currentNode->next;
            ss << "," << *currentNode->value;
        }
        ss << "]";
        return ss.str();
    }

    void deleteAt(int index) {
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

    int find(T value) {
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

private:
    std::shared_ptr<Node<T>> headNode;
    std::shared_ptr<Node<T>> tailNode;
    int numOfElements{};

    void dropLast() {
        tailNode = tailNode->prev;
    }
};


#endif //PLAYGROUND_DOUBLYLINKEDLIST_H
