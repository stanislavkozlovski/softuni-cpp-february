//
// Created by netherblood on 10.04.17.
//

#include "LowestTermFraction.h"

LowestTermFraction::LowestTermFraction(int nominator, int denominator) : Fraction(nominator, denominator) {
    // get them down to their lowest term
    this->simplifyFraction();
}

int LowestTermFraction::findGcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    this->findGcd(b%a, a);
}

LowestTermFraction LowestTermFraction::operator*(const LowestTermFraction &otherFraction) {
    return LowestTermFraction(this->nominator * otherFraction.nominator, this->denominator * otherFraction.denominator);
}

LowestTermFraction& LowestTermFraction::operator*=(const LowestTermFraction &otherFraction) {
    this->nominator *= otherFraction.nominator;
    this->denominator *= otherFraction.denominator;
    this->simplifyFraction();
    return *this;
}

LowestTermFraction LowestTermFraction::operator*(int num) {
    return LowestTermFraction(this->nominator * num, this->denominator);
}

LowestTermFraction &LowestTermFraction::operator*=(int num) {
    this->nominator *= num;
    this->simplifyFraction();
    return *this;
}

LowestTermFraction LowestTermFraction::operator/(const LowestTermFraction &otherFraction) {
    return LowestTermFraction(this->nominator * otherFraction.denominator, this->denominator * otherFraction.nominator);
}

LowestTermFraction& LowestTermFraction::operator/=(const LowestTermFraction &otherFraction) {
    this->nominator *= otherFraction.denominator;
    this->denominator *= otherFraction.nominator;
    this->simplifyFraction();
    return *this;
}

LowestTermFraction LowestTermFraction::operator/(int num) {
    return LowestTermFraction(this->nominator, this->denominator * num);
}

LowestTermFraction &LowestTermFraction::operator/=(int num) {
    this->denominator *= num;
    this->simplifyFraction();
    return *this;
}

LowestTermFraction LowestTermFraction::getReciprocal() {
    return LowestTermFraction(this->denominator, this->nominator);
}

void LowestTermFraction::simplifyFraction() {
    /* Simplifies the fraction to its lowest possible term*/
    int gcd = this->findGcd(nominator, denominator);
    this->nominator = nominator/gcd;
    this->denominator = denominator/gcd;
}
