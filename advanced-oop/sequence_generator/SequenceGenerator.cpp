//
// Created by netherblood on 07.04.17.
//

#include "SequenceGenerator.h"
#include<sstream>
#include <iostream>

using std::string;
using std::stringstream;


SequenceGenerator::SequenceGenerator(int startIndex, int endIndex) : startIdx(startIndex), endIdx(endIndex){
    this->length = endIndex - startIndex;
    this->numbers = new double[length];
}


SequenceGenerator::SequenceGenerator() {
    this->startIdx = 0;
    this->endIdx = 0;
}

SequenceGenerator::SequenceGenerator(const SequenceGenerator& sg) {
    this->startIdx = sg.startIdx;
    this->endIdx = sg.endIdx;
    this->length = sg.length;
    this->startName = sg.startName;
    this->endName = sg.endName;
    this->numbers = new double[this->length];

    // copy over the numbers
    for (int i = 0; i < std::min(sg.length, this->length); ++i) {
        this->numbers[i] = sg.numbers[i];
    }
}
SequenceGenerator::~SequenceGenerator() {
    delete[] this->numbers;
}


int SequenceGenerator::getRealIndex(int index) {
    int realIndex = index - this->startIdx;
    return realIndex;
}

double SequenceGenerator::getValue(int index) {
    if (this->startIdx > index || index >= this->endIdx) {
        std::cout << "Index out of bounds!" << std::endl;
        throw "Index out of bounds!";
    }
    int realIdx = this->getRealIndex(index);
    return this->numbers[realIdx];
}

string SequenceGenerator::getName(int index) {
    if (this->startIdx > index || index >= this->endIdx) {
        std::cout << "Index out of bounds!" << std::endl;
        throw "Index out of bounds!";
    }
    stringstream ss;
    ss << this->startName  << this->getValue(index) << this->endName;
    return ss.str();
}

SequenceGenerator &SequenceGenerator::operator=(const SequenceGenerator &sg) {
    this->startIdx = sg.startIdx;
    this->endIdx = sg.endIdx;
    this->length = sg.length;
    this->startName = sg.startName;
    this->endName = sg.endName;
    this->numbers = new double[this->length];

    // copy over the numbers
    for (int i = 0; i < std::min(sg.length, this->length); ++i) {
        this->numbers[i] = sg.numbers[i];
    }
}

