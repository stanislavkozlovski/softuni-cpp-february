#include <iostream>
#include "LowestTermFraction.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    LowestTermFraction lt = LowestTermFraction(10, 5);
    LowestTermFraction ltt = LowestTermFraction(10, 11);
    lt *= ltt;
    std::cout << lt.nominator << std::endl << "--" << std::endl << lt.denominator << std::endl;
    lt /= ltt;
    std::cout << lt.nominator << std::endl << "--" << std::endl << lt.denominator << std::endl;
    return 0;
}