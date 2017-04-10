#include <iostream>
#include "SequenceGenerator.h"
#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            FibonacciGenerator g(1, 5);
            FibonacciGenerator copyConstructred(g);
            FibonacciGenerator copyAssigned(1, 5);
            copyAssigned = g;
            std::cout << copyAssigned.getName(1) << " " << copyConstructred.getName(4) << " ";
            std::cout << (copyAssigned.getName(3) == copyConstructred.getName(3));

            SqrtGenerator s(1, 20);
            SqrtGenerator copyCon(s);
            SqrtGenerator copyAs(1, 10);
            copyAs = s;
            std::cout << copyAs.getName(4) << std::endl;
        }
    }
    return 0;
}