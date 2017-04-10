//
// Created by netherblood on 10.04.17.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H


#include <ostream>
#include "Node.h"

class LinkedList {
    Node* root;
    Node* last;
    size_t len;
public:
    class Iterator {
        Node* current;
    public:
        Iterator(Node* start) : current(start) { }
        Iterator& operator++() {
            this->current = this->current->next;
            return *this;
        }
        bool operator==(const Iterator& it) const {
            return this->current == it.current;
        }
        bool operator!=(const Iterator& it) const {
            return this->current != it.current;
        }

        int& operator*() {
            return current->value;
        }
    };
    LinkedList(int value);
    void add(int value);
    void remove(int value);
    Node* find(int value);
    bool contains(int value);
    size_t size();
    Iterator begin();
    Iterator end();
    friend std::ostream & operator<< (std::ostream &out, LinkedList const &t);
};


#endif //LINKED_LIST_LINKEDLIST_H
