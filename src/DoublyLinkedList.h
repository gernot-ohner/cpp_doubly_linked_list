//
// Created by gernotohner on 18.08.21.
//

#ifndef PLAYGROUND_DOUBLYLINKEDLIST_H
#define PLAYGROUND_DOUBLYLINKEDLIST_H

#include <memory>
#include <vector>

// start simple, just it's just a DLL of integers
struct Node {
    int value;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
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
    std::shared_ptr<Node> headNode;
    std::shared_ptr<Node> tailNode;
    int numOfElements;

    void dropLast();
};


#endif //PLAYGROUND_DOUBLYLINKEDLIST_H
