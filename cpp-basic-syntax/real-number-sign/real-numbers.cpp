#include <iostream>
using namespace std;

int main() {
    /*
    Write a program that shows the sign (+ or -) of the product of
    three real numbers without calculating it. Use a sequence of if
    statements.
    */
    double a, b, c;
    cin >> a >> b >> c;
    int negativeNumbersCount = (int)(a < 0) + (int)(b < 0) + (int)(c < 0);

    if (negativeNumbersCount % 2 == 0) {
        cout << "+";
    } else {
        cout << "-";
    }
    return 0;
}
