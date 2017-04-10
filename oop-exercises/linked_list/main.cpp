#include <iostream>
#include "LinkedList.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkedList ll = LinkedList(5);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.add(2);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.add(3);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.add(2);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.add(10);
    ll.add(10);
    ll.add(10);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.remove(10);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.remove(10);
    ll.remove(10);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.remove(5);
    std::cout << ll << "Size" << ll.size() << std::endl;
    ll.remove(2);
    ll.remove(2);
    std::cout << ll << "Size" << ll.size() << std::endl;



    // testing the iterator
    ll.add(2);
    ll.add(3);
    ll.add(2);
    ll.add(10);
    ll.add(10);
    ll.add(10);
    for (LinkedList::Iterator i = ll.begin(); i != ll.end(); ++i) {
        *i = 1;
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    for (int& number : ll) {
        std::cout << number << " ";
    }
    return 0;
}