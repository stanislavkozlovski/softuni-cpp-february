//
// Created by netherblood on 10.04.17.
//

#include <clocale>
#include "LinkedList.h"
#include "node.cpp"

template <typename DataType>
LinkedList<DataType>::LinkedList(DataType value) {
    this->root = std::make_shared<Node<DataType>>(value);
    this->last = NULL;
    this->len = 1;
}

template <class DataType>
void LinkedList<DataType>::add(DataType value) {
    NodePtr<DataType> newLast = std::make_shared<Node<DataType>>(value);
    this->len++;
    if (this->last == NULL) {
        newLast->prev = this->root;
        this->last = newLast;
        this->root->next = newLast;
    } else {
        newLast->prev = this->last;
        this->last->next = newLast;
        this->last = newLast;
    }

}

template <class DataType>
void LinkedList<DataType>::remove(DataType value) {
    Node<DataType>* nodeToRemove = this->find(value);
    if (nodeToRemove == NULL) {
        // Linked list does not contain value
        return;
    }
    this->len--;

    Node<DataType>* prevNode = nodeToRemove->prev;
    if (prevNode != NULL) {
        prevNode->next = nodeToRemove->next;
    }

    Node<DataType>* nextNode = nodeToRemove->next;
    if (nextNode != NULL) {
        nextNode->prev = prevNode;
        if (prevNode == NULL) {
            this->root = nextNode;
        }
    } else {
        // we are removing the last node
        this->last = prevNode;
    }

    delete  nodeToRemove;
}

template <class DataType>
NodePtr<DataType> LinkedList<DataType>::find(DataType value) {
    /* Iterate through the nodes, trying to find the right node */
    Node<DataType>* el = this->root;

    while(el != NULL && el->value != value) {
        el = el->next;
    }

    return el;
}

template <class DataType>
bool LinkedList<DataType>::contains(DataType value) {
    /* Returns a boolean indicating if the linked list contains the given value */
    return this->find(value) != NULL;
}

template <class DataType>
std::ostream& operator<< (std::ostream &out, LinkedList<DataType> const &t) {
    Node<DataType>* el = t.root;

    while(el != NULL) {
        out << el->value << " ";
        el = el->next;
    }

    return out;
}


template <class DataType>
size_t LinkedList<DataType>::size() {
    return this->len;
}

template <class DataType>
typename LinkedList<DataType>::Iterator LinkedList<DataType>::begin() {
    return LinkedList::Iterator(this->root);
}

template <class DataType>
typename LinkedList<DataType>::Iterator LinkedList<DataType>::end() {
    return LinkedList::Iterator(NULL);
}

template <class DataType>
LinkedList<DataType>::LinkedList(std::initializer_list<DataType> elements) {
    this->last = NULL;
    this->len = 0;
    for (auto el : elements) {
        if (this->len == 0) {
            this->root = std::make_shared<Node<DataType>>(el);
            this->len = 1;
        } else {
            this->add(el);
        }
    }
}

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList &lt){
    this->clear();

    NodePtr<DataType> el = lt.root;
    this->len = 1;
    this->root = std::make_shared<NodePtr<DataType> >(el->value);
    while(el != NULL) {
        el = el->next;
        if (el != NULL) {
            this->add(el->value);
        }
    }
}

template <class DataType>
LinkedList<DataType>::LinkedList(LinkedList&& lt) {
    this->len = lt.len;
    this->root = lt.root;
    this->last = lt.last;
}


template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator= (const LinkedList<DataType>& lt) {
    this->clear();

    NodePtr<DataType> el = lt.root;
    this->len = 1;
    this->root = std::make_shared<Node<DataType>>(el->value);
    while(el != NULL) {
        el = el->next;
        if (el != NULL) {
            this->add(el->value);
        }
    }
}

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator= (LinkedList<DataType>&& lt) {
    this->len = lt.len;
    this->root = lt.root;
    this->last = lt.last;
    lt.root = nullptr;
    lt.last = nullptr;
}

template <class DataType>
void LinkedList<DataType>::clear() {
    /*
     * Clears everything from the linked list
     * shared_ptr should clean themselves up
     */
    this->len = 0;
    this->root = NULL;
    this->last = NULL;
}

template <class DataType>
LinkedList<DataType>::~LinkedList() {
//    std::cout << "Called destructor of LL with start el " << this->root->value << std::endl;
    this->clear();
}