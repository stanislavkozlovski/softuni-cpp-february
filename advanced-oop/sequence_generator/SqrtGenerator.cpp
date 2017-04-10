//
// Created by netherblood on 07.04.17.
//

#include "SequenceGenerator.h"
#include "SqrtGenerator.h"
#include <cmath>

using std::sqrt;

void SqrtGenerator::GenerateSequence() {
    for (int i = 0; i < this->length; ++i) {
        this->numbers[i] = sqrt(this->startIdx + i);
    }
}

SqrtGenerator::SqrtGenerator(int startIndex, int endIndex) : SequenceGenerator(startIndex, endIndex){
    this->startName = "Sqrt(";
    this->endName = ")";
    this->GenerateSequence();
}