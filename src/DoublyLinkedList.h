//
// Created by gernotohner on 18.08.21.
//

#ifndef PLAYGROUND_DOUBLYLINKEDLIST_H
#define PLAYGROUND_DOUBLYLINKEDLIST_H

#include <memory>
#include <vector>

// start simple, just it's just a DLL of integers
struct Node {
//    std::unique_ptr<Node> next;
    int value;
//    std::unique_ptr<Node> prev;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    explicit DoublyLinkedList(int value);

    [[nodiscard]] int size() const;
    int at(int index);
    int head();
    int tail();

    void insert(int index, int value);
    void add(int value);

    std::string toString();

    void deleteAt(int index);

    int find(int value);

private:
    Node* headNode;
    Node* tailNode;
    int numOfElements;

    void dropLast();
};


#endif //PLAYGROUND_DOUBLYLINKEDLIST_H
