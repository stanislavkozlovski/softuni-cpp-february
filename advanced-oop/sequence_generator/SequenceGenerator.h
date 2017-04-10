//
// Created by netherblood on 07.04.17.
//

#ifndef SEQUENCE_GENERATOR_SEQUENCEGENERATOR_H
#define SEQUENCE_GENERATOR_SEQUENCEGENERATOR_H

#include<string>
using std::string;

class SequenceGenerator {
protected:
    int length;
    double* numbers;
    string startName, endName;
    int startIdx, endIdx;

    int getRealIndex(int index);
public:
     SequenceGenerator& operator = (const SequenceGenerator &t);
    SequenceGenerator();
    SequenceGenerator(const SequenceGenerator& sg);
    SequenceGenerator(int startIndex, int endIndex);
    ~SequenceGenerator();
    virtual void GenerateSequence() = 0;
    string getName(int index);
    double getValue(int index);
};


#endif //SEQUENCE_GENERATOR_SEQUENCEGENERATOR_H
