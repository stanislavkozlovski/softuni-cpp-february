#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

template<class NodeType>
class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    NodeType value;
    Node(NodeType value);

    bool operator==(const Node& nd);
};


#endif //LINKED_LIST_NODE_H
