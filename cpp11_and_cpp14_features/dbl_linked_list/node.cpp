//
// Created by netherblood on 10.04.17.
//

#include <clocale>
#include "Node.h"
template <class NodeType>
Node<NodeType>::Node(NodeType value) : value(value) {
    this->next = std::shared_ptr<Node>();
    this->prev = std::weak_ptr<Node>();
}

template <class NodeType>
bool Node<NodeType>::operator==(const Node &nd) {
    return this->value == nd.value && this->next == nd.next && this->prev == nd.prev;
}
