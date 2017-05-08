#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using std::stack;
using std::string;

unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}
int concat(int x, int y) {
    int temp = y;
    while (y != 0) {
        x *= 10;
        y /= 10;
    }
    return x + temp;
}
int main() {
    stack<int> numbers;
    string input;
    getline(std::cin, input);

    while (input != "end") {

        if (input == "sum") {
            int firstNum = numbers.top();
            numbers.pop();
            int secondNum = numbers.top();
            numbers.pop();

            numbers.push(firstNum+secondNum);
        } else if (input == "concat") {
            int firstNum = numbers.top();
            numbers.pop();
            int secondNum = numbers.top();
            numbers.pop();

            int secondNumModified = secondNum * 10;
//            int newNum;
            int newNum = std::stoi(std::to_string(secondNum) + std::to_string(firstNum));
            numbers.push(newNum);
        } else if (input == "discard") {
            numbers.pop();
        } else if (input == "subtract") {
            int firstNum = numbers.top();
            numbers.pop();
            int secondNum = numbers.top();
            numbers.pop();

            numbers.push(firstNum-secondNum);
        } else {
            // add a number
            int number = std::stoi(input);
            numbers.push(number);
        }

        getline(std::cin, input);
    }
    std::vector<int> numsToPrint;
    while (!numbers.empty()) {
        int num = numbers.top();
        numsToPrint.push_back(num);
        numbers.pop();
    }

    for (int i = numsToPrint.size()-1; i >= 0; --i) {
        std::cout << numsToPrint[i] << std::endl;
    }
    return 0;
}