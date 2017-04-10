#include <iostream>
#include "SmartString.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    SmartString s = "What up";
    s.changeWord(2, "down");
    std::cout << s << std::endl;
    return 0;
}