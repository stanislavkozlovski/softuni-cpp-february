//
// Created by netherblood on 07.04.17.
//

#ifndef SEQUENCE_PRINTER_SequencePrinter_H
#define SEQUENCE_PRINTER_SequencePrinter_H


class SequencePrinter {
public:
    virtual void print();
    void setSequence(const SequenceGenerator& sequence) = 0;
};


#endif //SEQUENCE_PRINTER_SequencePrinter_H
