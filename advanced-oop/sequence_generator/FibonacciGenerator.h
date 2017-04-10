//
// Created by netherblood on 07.04.17.
//

#ifndef SEQUENCE_GENERATOR_FIBONACCIGENERATOR_H
#define SEQUENCE_GENERATOR_FIBONACCIGENERATOR_H

#include "SequenceGenerator.h"

class FibonacciGenerator : public SequenceGenerator {
private:
    int genFib(int num);
public:
    FibonacciGenerator(int startIndex, int endIndex);
    void GenerateSequence();
};


#endif //SEQUENCE_GENERATOR_FIBONACCIGENERATOR_H
