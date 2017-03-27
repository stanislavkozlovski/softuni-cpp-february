#include <iostream>
#include <stdexcept>
#include "smart_array.cpp"
#include "smart_matrix.cpp"

int main() {
    /* Test the Smart Array */
    SmartArray smArr;
    std::cout << smArr.size;
    for (size_t i = 0; i < 34; i++) {
        if (i >= 17) {
            smArr.Append(4);
        } else {
            smArr.Append(3);
        }
    }
    for (size_t i = 0; i < smArr.size; i++) {
        std::cout << smArr[i] << std::endl;
    }

    smArr.CutTo(smArr.size/2);
    std::cout << "REMOVED HALF" << std::endl;

    for (size_t i = 0; i < smArr.size; i++) {
        std::cout << smArr[i] << std::endl;
    }

    std::cout << smArr[1] << std::endl;
    smArr[1] = 233;
    std::cout << smArr[1] << std::endl;

    /* Test the Smart Matrix */
    SmartMatrix matrix(4, 4);
    std::cout << matrix.toString() << std::endl;
    return 0;
}