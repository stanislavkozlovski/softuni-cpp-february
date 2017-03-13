#include <iostream>

bool assertArrayEquals(int* expected, int expectedSize, int* actual, int actualSize);

int main() {
    int* expected = new int[5]{1, 2, 3, 4, 5};
    int* actual = new int[6]{1, 2, 3, 4, 5, 6};
    
    std::cout << (assertArrayEquals(expected, 5, actual, 6) == 0) << std::endl;
    std::cout << (assertArrayEquals(new int[3] {3,2,1}, 3, new int[3] {3,2,1}, 3) == 1) << std::endl;
    std::cout << (assertArrayEquals(new int[1] {0}, 1, new int[1] {0}, 1) == 1) << std::endl;
    std::cout << (assertArrayEquals(new int[6] {0, 2, 3, 4, 5, 6}, 6, new int[6] {0, 2, 3, 4, 5, 5}, 6) == 0) << std::endl;
    
    
    return 0;
}

bool assertArrayEquals(int* expected, int expectedSize, int* actual, int actualSize) {
    if (expectedSize != actualSize) {
        // Different sizes mean that they're different arrays
        return false;
    }

    for (int i = 0; i < expectedSize; i++)
    {
        if (expected[i] != actual[i]) {
            return false;
        }
    }

    return true;
}
