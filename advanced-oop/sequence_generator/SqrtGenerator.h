//
// Created by netherblood on 07.04.17.
//

#ifndef SEQUENCE_GENERATOR_SQRTGENERATOR_H
#define SEQUENCE_GENERATOR_SQRTGENERATOR_H

#include "SequenceGenerator.h"

class SqrtGenerator : public SequenceGenerator {
public:
    SqrtGenerator(int startIndex, int endIndex);
    void GenerateSequence();
};


#endif //SEQUENCE_GENERATOR_SQRTGENERATOR_H
