#include <iostream>

int main() {
    int first = 11;
    int second = 10;

    std::cout << "First is " << first << " and Second is " << second << std::endl;

    if (first > second) {
        // swap using XOR
        first = first^second;
        second = first^second;
        first = first^second;
        std::cout << "Swapped variales" << std::endl;
    }

    std::cout << "First is " << first << " and Second is " << second << std::endl;
    return 0;
}