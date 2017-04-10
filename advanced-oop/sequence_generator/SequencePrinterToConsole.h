//
// Created by netherblood on 10.04.17.
//

#ifndef SEQUENCE_GENERATOR_SEQUENCEPRINTERTOCONSOLE_H
#define SEQUENCE_GENERATOR_SEQUENCEPRINTERTOCONSOLE_H


#include "SequencePrinter.h"

class SequencePrinterToConsole : public SequencePrinter {
public:
    virtual void print();
    virtual void setSequence(SequenceGenerator& sequence);
};


#endif //SEQUENCE_GENERATOR_SEQUENCEPRINTERTOCONSOLE_H
