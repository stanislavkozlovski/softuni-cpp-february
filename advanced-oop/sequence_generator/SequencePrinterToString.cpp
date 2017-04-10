//
// Created by netherblood on 10.04.17.
//

#include "SequencePrinterToString.h"
#include <sstream>
#include <iostream>

using std::stringstream;

void SequencePrinterToString::print() {
    stringstream ss;
    ss << " ";
    std::cout << this->sequence->getStart() << std::endl;
    std::cout << this->sequence->getEnd() << std::endl;
    for (int i = this->sequence->getStart(); i < this->sequence->getEnd(); ++i) {
        ss << this->sequence->getName(i) << " ";
    }

    this->string += ss.str();
}


SequencePrinterToString::SequencePrinterToString(std::string &str) : string(str) { }

void SequencePrinterToString::setSequence(SequenceGenerator& sequence) {
    this->sequence = &sequence;
}
