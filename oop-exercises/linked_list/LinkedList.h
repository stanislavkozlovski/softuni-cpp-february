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
    LinkedList(int value);
    void add(int value);
    void remove(int value);
    Node* find(int value);
    bool contains(int value);
    size_t size();
    friend std::ostream & operator<< (std::ostream &out, LinkedList const &t);
};


#endif //LINKED_LIST_LINKEDLIST_H
