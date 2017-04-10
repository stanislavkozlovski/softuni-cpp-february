//
// Created by netherblood on 10.04.17.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H


class Node {
public:
    Node* next;
    Node* prev;
    int value;
    Node(int value);

    bool operator==(const Node& nd);
};


#endif //LINKED_LIST_NODE_H
