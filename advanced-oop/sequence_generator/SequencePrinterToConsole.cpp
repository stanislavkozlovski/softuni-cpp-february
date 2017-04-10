//
// Created by netherblood on 10.04.17.
//

#include <iostream>
#include "SequencePrinterToConsole.h"

void SequencePrinterToConsole::print() {
    for (int i = this->sequence->getStart(); i < this->sequence->getEnd(); ++i) {
        std::cout << " " << this->sequence->getName(i) << " ";
    }
    std::cout << std::endl;
}

void SequencePrinterToConsole::setSequence(SequenceGenerator &sequence) {
    this->sequence = &sequence;
}
