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
    this->size = 0;
    // copy copy of every node pointer :o
     /* Iterates through the whole list and deletes the nodes */
    this->removeAll();
//    std::cout << other.toString();
    if (other.size == 0) {
        return;
    }
    if (other.size == 1) {
        this->add(other.head->getValue());
    } else {
        this->add(other.head->getValue());
        Node* currNode = other.head->getNext();
        while (currNode != nullptr) {
            this->add(currNode->getValue());
            currNode = currNode->getNext();
        }
    }

}

List::~List() {
    /* Iterates through the whole list and deletes the nodes */
    this->removeAll();
}

T List::first() const {
    /* Returns the first value of the list*/
    return this->head->getValue();
}

void List::add(T value) {
    if (this->head == nullptr && this->tail == nullptr) {
        this->head = this->tail = new Node(value, nullptr, nullptr);
        this->size++;
        return;
    }

    Node* newTail = new Node(value, this->tail, nullptr);
    this->tail->setNext(newTail);
    this->tail = newTail;
    this->size++;
}

void List::addAll(const List &other) {
    size_t addedNodes = 0;
    size_t numToAdd = other.size;
    Node* currNode = other.head;
    while (currNode != nullptr || addedNodes != numToAdd) {
        this->add(currNode->getValue());
        addedNodes++;
        currNode = currNode->getNext();
    }
}

void List::removeFirst() {
    if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else if (this->size == 2) {
        delete this->head;
        this->tail->setPrev(nullptr);
        this->tail->setNext(nullptr);
        this->head = this->tail;
    } else {
        // Remove the current head by deleting it and making the next node point to it
        Node* newHead = this->head->getNext();
        newHead->setPrev(nullptr);
        delete this->head;
        this->head = newHead;
    }
    this->size--;
}

void List::removeAll() {
     /* Iterates through the whole list and deletes the nodes */
    if (this->size >= 1) {
        Node* prevNode = this->head;
        Node* currNode = this->head->getNext();
        while (currNode != nullptr) {
            delete prevNode;
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        delete prevNode;
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
    List reversed;

    Node* currentNode = l.tail;
    while (currentNode != nullptr) {
        reversed.add(currentNode->getValue());
        currentNode = currentNode->getPrev();
    }

    return reversed;
}

std::string List::toString() const {
    if (this->size == 0) {
        return "";
    }

    std::stringstream ss;
    ss << this->head->getValue();
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


