//
// Created by netherblood on 19.04.17.
//

#include "List.h"
#include <sstream>
#include <iostream>


List::List() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

List::List(const List &other) {
    // copy copy of every node pointer :o
     /* Iterates through the whole list and deletes the nodes */
    this->removeAll();
//    std::cout << other.toString();
    std::istringstream lineStream(other.toString());
    int value;
    while (lineStream >> value) {
        this->add(value);
    }
}

List::~List() {
    /* Iterates through the whole list and deletes the nodes */
    if (this->size == 0) {
        return;
    }
    Node* prevNode = this->head;
    Node* currNode = this->head->getNext();
    while (currNode != nullptr) {
        delete prevNode;
        prevNode = currNode;
        currNode = currNode->getNext();
    }

    delete prevNode;
}

T List::first() const {
    if (this->head == nullptr) {
        throw "Aaa";
    }
    return this->head->getValue();
}

void List::add(T value) {
    if (this->head == nullptr && this->tail == nullptr) {
        this->head = this->tail = new Node(value, nullptr, nullptr);
    } else if (this->size == 1) {
        // Adding the tail, set it and make the head point to it
        this->tail = new Node(value, this->head, nullptr);
        this->head->setNext(this->tail);
    } else {
        // add a tail
        Node* newTail = new Node(value, this->tail, nullptr);
        this->tail->setNext(newTail);
        this->tail = newTail;
    }
    this->size++;
}

void List::addAll(const List &other) {
    size_t addedNodes = 0;
    size_t numToAdd = other.size;
    // TODO: Check in case of single list
    Node* currNode = other.head;
    while (currNode != nullptr || addedNodes != numToAdd) {
        this->add(currNode->getValue());
        addedNodes++;
        currNode = currNode->getNext();
    }
}

void List::removeFirst() {
    if (this->size == 0) {
        throw "FUCK";
    }
    if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else if (this->size == 2) {
        delete this->head;
        this->head = this->tail;
    } else {
        // Remove the current head by deleting it and making the next node point to it
        Node* newHead = this->head->getNext();
        newHead->setPrev(nullptr);
        delete this->head;
        this->head = newHead;
//         Remove the current tail by deleting it and making the previous node the tail
//        Node* prevNode = this->tail->getPrev();
//        prevNode->setNext(nullptr);
//        delete this->tail;
//
//        this->tail = prevNode;
    }
    this->size--;
}

void List::removeAll() {
     /* Iterates through the whole list and deletes the nodes */
    if (this->size == 0) {
        this->head = this->tail = nullptr;
        return;
    }
    size_t removedNodes = 0;
    size_t nodesToRemove = this->size;
    Node* prevNode = this->head;
    Node* currNode = this->head->getNext();
    while (currNode != nullptr) {
        delete prevNode;
        removedNodes++;
        prevNode = currNode;
        currNode = currNode->getNext();
    }
    delete prevNode;
    removedNodes++;
    if (removedNodes != nodesToRemove) {
        throw "AA";
    }
    this->head = this->tail = nullptr;
    this->size = 0;
}

size_t List::getSize() const {
    return this->size;
}

bool List::isEmpty() const {
    return this->size == 0;
}

List List::getReversed(List l) {
    if (l.size == 1) {
        List reversed;
        reversed.add(l.tail->getValue());
        return reversed;
    }

    List reversed;
    Node* currentNode = l.tail;
    while (currentNode != nullptr) {
        reversed.add(currentNode->getValue());
        currentNode = currentNode->getPrev();
    }

    return reversed;
}

std::string List::toString() const {
    std::stringstream ss;
    if (this->size == 0) {
        return "";
    }
    ss << this->head->getValue();
    if (this->size == 1) {
        return ss.str();
    }
    Node* currNode = this->head->getNext();
    while (currNode != nullptr) {
        ss << " " << currNode->getValue();
        currNode = currNode->getNext();
    }
    return ss.str();
}

List &List::operator<<(const T &value) {
    this->add(value);
    return *this;
}

List &List::operator<<(const List &other) {
    this->addAll(other);
    return *this;
}

List &List::operator=(const List &other) {
    this->removeAll();
//    this->~List();
    this->addAll(other);
    return *this;
}


/************************* NODE ***************************/


List::Node::Node(T value, List::Node *prev, List::Node *next) : value(value), prev(prev), next(next) {
    this->value = value;
    this->prev = prev;
    this->next = next;
}

T List::Node::getValue() const {
    return this->value;
}

void List::Node::setValue(T value) {
    this->value = value;
}

List::Node *List::Node::getNext() const {
    return this->next;
}

void List::Node::setNext(List::Node *next) {
    this->next = next;
}

List::Node *List::Node::getPrev() const {
    return this->prev;
}

void List::Node::setPrev(List::Node *prev) {
    this->prev = prev;
}


