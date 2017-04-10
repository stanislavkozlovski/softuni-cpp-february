//
// Created by netherblood on 10.04.17.
//

#ifndef SEQUENCE_GENERATOR_SEQUENCEPRINTER_H
#define SEQUENCE_GENERATOR_SEQUENCEPRINTER_H


#include "SequenceGenerator.h"

class SequencePrinter {
protected:
    SequenceGenerator* sequence;
public:
    virtual void print() = 0;
    virtual void setSequence(SequenceGenerator& sequence) = 0;
};


#endif //SEQUENCE_GENERATOR_SEQUENCEPRINTER_H
