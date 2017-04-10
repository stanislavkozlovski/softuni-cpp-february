//
// Created by netherblood on 10.04.17.
//

#ifndef FRACTION_LOWESTTERMFRACTION_H
#define FRACTION_LOWESTTERMFRACTION_H


#include "Fraction.h"

class LowestTermFraction : public Fraction {
    int findGcd(int a, int b);
    void simplifyFraction();
public:
    LowestTermFraction operator*(int num);
    LowestTermFraction& operator*=(int num);
    LowestTermFraction operator*(const LowestTermFraction& otherFraction);
    LowestTermFraction& operator*=(const LowestTermFraction &otherFraction);

    LowestTermFraction operator/(const LowestTermFraction &otherFraction);
    LowestTermFraction& operator/=(const LowestTermFraction &otherFraction);
    LowestTermFraction operator/(int num);
    LowestTermFraction& operator/=(int num);

    LowestTermFraction getReciprocal();
    LowestTermFraction(int nominator, int denominator);
};


#endif //FRACTION_LOWESTTERMFRACTION_H
