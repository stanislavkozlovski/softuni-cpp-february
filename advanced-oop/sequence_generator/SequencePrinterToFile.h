//
// Created by netherblood on 10.04.17.
//

#ifndef SEQUENCE_GENERATOR_SEQUENCEPRINTERTOFILE_H
#define SEQUENCE_GENERATOR_SEQUENCEPRINTERTOFILE_H


#include "SequencePrinter.h"
#include <fstream>
using std::ofstream;

class SequencePrinterToFile : public SequencePrinter {
    ofstream fs;
public:
    SequencePrinterToFile(std::string path);
    virtual void print();
    virtual void setSequence(SequenceGenerator& sequence);
};


#endif //SEQUENCE_GENERATOR_SEQUENCEPRINTERTOFILE_H
