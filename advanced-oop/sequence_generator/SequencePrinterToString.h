//
// Created by netherblood on 10.04.17.
//

#ifndef SEQUENCE_GENERATOR_SEQUENCEPRINTERTOSTRING_H
#define SEQUENCE_GENERATOR_SEQUENCEPRINTERTOSTRING_H


#include "SequencePrinter.h"

class SequencePrinterToString : public SequencePrinter {
    std::string& string;
public:
    SequencePrinterToString(std::string& str);
    virtual void print();
    virtual void setSequence(SequenceGenerator& sequence);
};


#endif //SEQUENCE_GENERATOR_SEQUENCEPRINTERTOSTRING_H
