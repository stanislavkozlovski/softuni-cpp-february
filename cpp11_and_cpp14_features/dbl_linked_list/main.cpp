#include <iostream>
#include "LinkedList.cpp"

LinkedList<std::string> testMoveAssignment() {
    return LinkedList<std::string> {"babababa", "rarara"};
}


int main() {
    while (1) {
        LinkedList<std::string> fam = {"father", "mother", "sister"};
        LinkedList<std::string> tank("tk");
        tank = fam;
        tank = testMoveAssignment();
    }
    LinkedList<std::string> fam = {"father", "mother", "sister"};
    std::cout << fam.size() << std::endl;
    for (auto f : fam) {
        std::cout << f << std::endl;
    }

    LinkedList<std::string> words = LinkedList<std::string>("sup");
    words.add("Guardians");
    words.add("galaxy");
    for (auto word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}

