//
// Created by gernotohner on 18.08.21.
//

#include <sstream>
#include "DoublyLinkedList.h"

int DoublyLinkedList::size() const {
    return this->num_of_elements;
}

DoublyLinkedList::DoublyLinkedList(int value) {
    Node *newHeadNode = new Node{.value = value};
    this->headNode = newHeadNode;
    this->tailNode = newHeadNode;
    this->num_of_elements = 1;
}

void DoublyLinkedList::add(int value) {
    // TODO this does not handle setting prev right
    Node *newNode = new Node{.value = value};
    this->tailNode->next = newNode;
    this->tailNode = newNode;
    this->num_of_elements++;
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
    // TODO this does not handle updating tailNode right
    // TODO this also doesn't handle the case where index is too large right
    // TODO this also doesn't handle the case where index points to one past the last current index
    //   i.e. where you want to insert an element in the last position (i.e. add)
    int i = 0;
    Node *currentNode = headNode;
    while (i < index - 1) {
        currentNode = currentNode->next;
        i++;
    }
    Node *newNode = new Node{.value = value};
    Node *nextNode = currentNode->next;

    // currentnode->next = newnode
    currentNode->next = newNode;
    // newnode->previous = currentnode
    newNode->prev = currentNode;
    // nextnode->previous = newnode
    nextNode->prev = newNode;
    // newnode->next = nextnode
    newNode->next = nextNode;


    num_of_elements++;
}

Node *DoublyLinkedList::head() {
    return this->headNode;
}

Node *DoublyLinkedList::tail() {
    return this->tailNode;
}
