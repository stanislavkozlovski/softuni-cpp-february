#include <iostream>
#include "LinkedList.cpp"
#include <unordered_set>

LinkedList<std::string> testMoveAssignment() {
    return LinkedList<std::string> {"babababa", "rarara"};
}


int main() {
    while (1) {
        LinkedList<std::string> fam = {"father", "mother", "sister"};
        LinkedList<std::string> tank("tk");
        std::unordered_set<LinkedList<std::string>> llSet;
        llSet.insert(tank);  // some weird shared_ptr error, no idea what's causing it
        std::cout << "Set has " << llSet.size() << " elements" << std::endl;
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

