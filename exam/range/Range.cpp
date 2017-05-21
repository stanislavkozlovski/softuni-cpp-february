//
// Created by netherblood on 21.05.17.
//

#include <iostream>
#include "Range.h"

Range::Range() {
    this->valueCounts;
    this->rangeFirst = 0;
    this->rangeLength = 0;
}

void Range::add(T value) {
    if (this->rangeLength == 0) {
        this->valueCounts = new size_t[32];
        this->rangeFirst = value;
        this->valueCounts[0] = 1;
        rangeLength = 1;
        return;
    }

    T firstVal = this->rangeFirst;
    T endVal = this->rangeFirst + (this->rangeLength-1);  // TODO: ???

    if (firstVal <= value && endVal >= value) {
        // in the array
        size_t index = value - this->rangeFirst;
        this->valueCounts[index]++;
    } else {
        // outside the array
        if (firstVal > value) {
            // found new minimum, need to rebuild
            this->resize(value, endVal);
//            std::cout << "!!! THIS SHOULD BE ZERO" << this->valueCounts[0] << std::endl;
            this->valueCounts[0] = 1;
        } else if (endVal < value) {
            // found new maximum, need to rebuild
            this->resize(firstVal, value);
//            std::cout << "!!! THIS SHOULD BE ZERO" << this->valueCounts[this->rangeLength-1] << std::endl;
            this->valueCounts[this->rangeLength-1] = 1;
        }
    }
    // TODO: Check if its in the array and add
    // TODO: Otherwise, resize and increase size
}

size_t Range::getCount(T value) const {
    size_t index = value - this->rangeFirst;
    if (index < 0 || index >= this->rangeLength) {
        // tank
        return 0;
//        throw "tank";
    }


    return this->valueCounts[index];
}

void Range::clear() {
    this->rangeFirst = 0;
    this->rangeLength = 0;
    delete this->valueCounts;
}

void Range::resize(T first, T last) {
    size_t newLength = last-first;
    newLength++;
    if (newLength < this->rangeLength) {
        throw "tank";
    }
//    if (newLength == 1) {
//        newLength++;
//    }
    size_t* newRange = new size_t[newLength];
    for (int i = 0; i < newLength; ++i) {
        newRange[i] = 0;
    }
    // copy the stuff
    // TODO: Int i is assigned to T ???
    for (int i = 0; i < this->rangeLength; ++i) {
        T oldValue = i + this->rangeFirst;
        size_t oldCount = this->valueCounts[i];

        int newIdx = oldValue - first;
        newRange[newIdx] = oldCount;
    }

    this->clear();
    this->rangeFirst = first;
    this->rangeLength = newLength;
    this->valueCounts = newRange;
}

bool Range::empty() const {
    return this->rangeLength == 0;
}

Range::~Range() {
    this->clear();
}

Range::Range(const Range &other) {
    this->rangeLength = other.rangeLength;
    this->rangeFirst = other.rangeFirst;
    // should copy them over
    this->valueCounts = this->copyValues(other.valueCounts, other.rangeLength);

//    other.clear();
}

Range &Range::operator=(const Range &other) {
    this->rangeLength = other.rangeLength;
    this->rangeFirst = other.rangeFirst;
    // should copy them over
    this->valueCounts = this->copyValues(other.valueCounts, other.rangeLength);

    return *this;  // TODO: Should not be correct
}

