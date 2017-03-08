#include <iostream>
using namespace std;
/*
Write a program that calculates the greatest common divisor
(GCD) of given two numbers. Use the Euclidean algorithm (find it
in Internet)
*/

int gcd(int a, int b) {
    while (b != 0) {
        int oldB = b;
        b = a % b;
        a = oldB;
    }
    return a;
}

int main() {
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;
    cout << "The GCD of " << firstNum << " and " << secondNum << " is: " << gcd(firstNum, secondNum) << endl;
    return 0;
}