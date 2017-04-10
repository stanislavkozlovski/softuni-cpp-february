//
// Created by netherblood on 07.04.17.
//
#include "SequenceGenerator.h"
#include "FibonacciGenerator.h"


FibonacciGenerator::FibonacciGenerator(int startIndex, int endIndex) : SequenceGenerator(startIndex, endIndex){
    this->startName = "Fibonacci ";
    this->endName = "";
    this->GenerateSequence();
}

void FibonacciGenerator::GenerateSequence() {
    // INCREDIBLY INEFFICIENT
    for (int i = 0; i < this->length; ++i) {
        this->numbers[i] = this->genFib(this->startIdx + i);
    }
}

int FibonacciGenerator::genFib(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1 || num == 2) {
        return 1;
    }

    return genFib(num-1) + genFib(num-2);
}

