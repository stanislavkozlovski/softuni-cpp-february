#include <iostream>

/*
Write a program that prints all the numbers from 1 to N
*/
int main() {
    int n;
    std::cin >> n;
    for (size_t i = 1; i <= n; i++) {
        std::cout << i << std::endl;
    }
    return 0;
}