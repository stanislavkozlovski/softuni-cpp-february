#include <iostream>
#include "Energy.h"

int main() {
    // Fat(3); should not compile
    // UnsaturatedFat(3); should not compile
    MonounsaturatedFat(3); // should compile
    PolyunsaturatedFat(3); // should compile
    // Carbohydrate(3);  should not compile
    Starch(3);
    Fiber(3);
    Sugar sugar = Sugar(3);
    sugar += Fiber(10);
    std::cout << sugar.getGrams() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
