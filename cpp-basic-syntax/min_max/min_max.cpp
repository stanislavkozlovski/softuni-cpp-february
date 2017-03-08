#include <iostream>
#include <limits>
using namespace std;

int main() {
    int numbersCount;
    cout << "Enter the count of numbers you're about to put in!" << endl;
    cin >> numbersCount;
    int minNumber = std::numeric_limits<int>::max(), maxNumber = 0;

    for (int i = 0; i < numbersCount; i++) {
        int currentNumber;
        cin >> currentNumber;
        if (currentNumber < minNumber) {
            minNumber = currentNumber;
        }
        if (currentNumber > maxNumber) {
            maxNumber = currentNumber;
        }
    }

    cout << "Max Number is: " << maxNumber << endl << "Min Number is: " << minNumber << endl;

    return 0;
}