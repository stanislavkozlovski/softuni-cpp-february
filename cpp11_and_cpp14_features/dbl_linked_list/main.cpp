#include <iostream>
#include "LinkedList.cpp"
int main() {
    LinkedList<std::string> words = LinkedList<std::string>("sup");
    words.add("Guardians");
    words.add("galaxy");
    for (auto word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}