//
// Created by netherblood on 10.04.17.
//

#include <clocale>
#include "LinkedList.h"

LinkedList::LinkedList(int value) {
    this->root = new Node(value);
    this->last = NULL;
    this->len = 1;
}

void LinkedList::add(int value) {
    Node* newLast = new Node(value);
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

void LinkedList::remove(int value) {
    Node* nodeToRemove = this->find(value);
    if (nodeToRemove == NULL) {
        // Linked list does not contain value
        return;
    }
    this->len--;

    Node* prevNode = nodeToRemove->prev;
    if (prevNode != NULL) {
        prevNode->next = nodeToRemove->next;
    }

    Node* nextNode = nodeToRemove->next;
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

Node* LinkedList::find(int value) {
    /* Iterate through the nodes, trying to find the right node */
    Node* el = this->root;

    while(el != NULL && el->value != value) {
        el = el->next;
    }

    return el;
}

bool LinkedList::contains(int value) {
    /* Returns a boolean indicating if the linked list contains the given value */
    return this->find(value) != NULL;
}

std::ostream& operator<< (std::ostream &out, LinkedList const &t) {
    Node* el = t.root;

    while(el != NULL) {
        out << el->value << " ";
        el = el->next;
    }

    return out;
}

size_t LinkedList::size() {
    return this->len;
}
