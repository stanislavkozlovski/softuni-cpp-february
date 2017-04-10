//
// Created by netherblood on 10.04.17.
//

#include "SequencePrinterToFile.h"

SequencePrinterToFile::SequencePrinterToFile(std::string path) {
    this->fs.open(path, ofstream::out);
}

void SequencePrinterToFile::print() {
    for (int i = this->sequence->getStart(); i < this->sequence->getEnd(); ++i) {
        this->fs << this->sequence->getName(i);
    }
    this->fs.close();
}

void SequencePrinterToFile::setSequence(SequenceGenerator &sequence) {
    this->sequence = &sequence;
}
