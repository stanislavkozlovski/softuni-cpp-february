//
// Created by netherblood on 10.04.17.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H


#include <ostream>
#include "Node.h"

template<class DataType>
class LinkedList {
    Node<DataType>* root;
    Node<DataType>* last;
    size_t len;
public:
    class Iterator {
        Node<DataType>* current;
    public:
        Iterator(Node<DataType>* start) : current(start) { }
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

        DataType& operator*() {
            return current->value;
        }
    };
    LinkedList(std::initializer_list<DataType> initList);
    LinkedList(DataType value);
    
    // Rule of five
    ~LinkedList();
    LinkedList(const LinkedList& lt);
    LinkedList(LinkedList&& lt);
    LinkedList& operator= (const LinkedList& lt);
    LinkedList& operator= (LinkedList&& lt);
    // Rule of five ^

    void clear();
    void add(DataType value);
    void remove(DataType value);
    Node<DataType>* find(DataType value);
    bool contains(DataType value);
    size_t size();
    Iterator begin();
    Iterator end();
    friend std::ostream & operator<< (std::ostream &out, LinkedList<DataType> const &t);
};


#endif //LINKED_LIST_LINKEDLIST_H
