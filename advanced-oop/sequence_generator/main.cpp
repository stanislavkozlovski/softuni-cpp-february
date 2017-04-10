#include <iostream>
#include "SequenceGenerator.h"
#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"
#include "SequencePrinterToString.h"
#include "SequencePrinterToFile.h"
#include "SequencePrinterToConsole.h"

void testSequencePrinterToString();
void testSequencePrinterToFile();
void memoryLeakTest();
void testSequencePrinterToConsole();

int main() {
    std::cout << "Hello, World!" << std::endl;


    return 0;
}

void testSequencePrinterToConsole() {
    SqrtGenerator sqGen = SqrtGenerator(100, 200);
    auto sq = SequencePrinterToConsole();
    sq.setSequence(sqGen);
    sq.print();
}

void testSequencePrinterToFile() {
    SqrtGenerator sqGen = SqrtGenerator(2, 4);
    std::string YOUR_PATH = "/home/netherblood/CPProjects/cpp-softuni-february/softuni-cpp-february/advanced-oop/sequence_generator/this.txt";
    auto sq = SequencePrinterToFile(YOUR_PATH);
    sq.setSequence(sqGen);
    sq.print();
    std::cout << "Check the file :), Should have Sqrt(4) Sqrt(9)" << std::endl;
}

void testSequencePrinterToString() {
    std::string testStr = "test string :)";
    FibonacciGenerator fbGen = FibonacciGenerator(1, 10);
    auto sq = SequencePrinterToString(testStr);
    sq.setSequence(fbGen);
    sq.print();
    std::cout << testStr;
    // test string :) Fibonacci 1 Fibonacci 1 Fibonacci 2 Fibonacci 3 Fibonacci 5 Fibonacci 8 Fibonacci 13 Fibonacci 21 Fibonacci 34
}

void memoryLeakTest() {
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 10000; ++j) {
            FibonacciGenerator g(1, 5);
            FibonacciGenerator copyConstructred(g);
            FibonacciGenerator copyAssigned(1, 5);
            copyAssigned = g;
            std::cout << copyAssigned.getName(1) << " " << copyConstructred.getName(4) << " ";
            std::cout << (copyAssigned.getName(3) == copyConstructred.getName(3));

            SqrtGenerator s(1, 20);
            SqrtGenerator copyCon(s);
            SqrtGenerator copyAs(1, 10);
            copyAs = s;
            std::cout << copyAs.getName(4) << std::endl;
        }
    }
}