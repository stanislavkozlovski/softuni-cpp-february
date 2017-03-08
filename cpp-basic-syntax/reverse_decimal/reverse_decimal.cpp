#include <iostream>

int reverseNumber(int n) {
    int reverseNumber = 0;
    while (n != 0) {
        int digit = n % 10;

        reverseNumber *= 10;
        reverseNumber += digit;

        n /= 10;
    }

    return reverseNumber;
}

bool checkReverseNumbers() {
    return reverseNumber(103) == 301
        && reverseNumber(5042) == 2405
        && reverseNumber(1) == 1
        && reverseNumber(41831) == 13814;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverseNumber(n) << std::endl;
    std::cout << "The function " << (checkReverseNumbers() ? "works" : "doesn't work'") << std::endl;
    return 0;
}