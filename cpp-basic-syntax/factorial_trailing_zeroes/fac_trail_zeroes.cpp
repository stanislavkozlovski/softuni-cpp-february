/*
Write a program that calculates for given N how many trailing
zeros present at the end of the number N!. Examples N = 10, N! =
3628800, answer 2; N! = 2432902008176640000, answer: 4. Make
sure your program works for N up to 50 000
*/
#include <iostream>
#include <cmath>

int getTrailingZeroes(int n) {
    /*
        The trailing zeroes of the factorial of N is the count of the multiples of five in N
    */
    int trailingZeroesCount;
    int result;
    int fivePower = 1;

    result = n / std::pow(5, fivePower);
    trailingZeroesCount += result;

    while (result != 0) {
        fivePower++;
        result = n / std::pow(5, fivePower);
        trailingZeroesCount += result;
    }

    return trailingZeroesCount;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << getTrailingZeroes(n) << std::endl;
    return 0;
}