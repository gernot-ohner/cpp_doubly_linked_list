//
// Created by gernotohner on 18.08.21.
//

#ifndef PLAYGROUND_DOUBLYLINKEDLIST_H
#define PLAYGROUND_DOUBLYLINKEDLIST_H

#include <memory>
#include <vector>

// start simple, just it's just a DLL of integers
struct Node {
    std::shared_ptr<std::string> value;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
};

class DoublyLinkedList {
public:
    explicit DoublyLinkedList(std::string value);

    [[nodiscard]] int size() const;
    std::string at(int index);
    std::string head();
    std::string tail();

    void insert(int index, std::string value);
    void add(std::string value);

    std::string toString();

    void deleteAt(int index);

    int find(std::string value);

private:
    std::shared_ptr<Node> headNode;
    std::shared_ptr<Node> tailNode;
    int numOfElements;

    void dropLast();
};


#endif //PLAYGROUND_DOUBLYLINKEDLIST_H
