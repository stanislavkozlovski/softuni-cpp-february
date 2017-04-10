//
// Created by netherblood on 10.04.17.
//

#include <clocale>
#include "Node.h"

Node::Node(int value) : value(value) {
    this->next = NULL;
    this->prev = NULL;
}

bool Node::operator==(const Node &nd) {
    return this->value == nd.value && this->next == nd.next && this->prev == nd.prev;
}
