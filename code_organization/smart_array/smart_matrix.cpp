#pragma once

#include <vector>
#include <string>
#include <sstream>
#include "smart_array.h"
#include "smart_matrix.h"

using std::vector;
using std::string;
using std::stringstream;


SmartMatrix::SmartMatrix(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        this->matrix.push_back(SmartArray(cols));
    }
}

SmartArray &SmartMatrix::operator[](const int row) {
    return this->matrix[row];
}

string SmartMatrix::toString() {
    stringstream ss;

    for (int rowIdx = 0; rowIdx < matrix.size(); rowIdx++) {
        SmartArray row = matrix[rowIdx];
        for (int colIdx = 0; colIdx < row.size; colIdx++) {
            ss << row[colIdx] << " ";
        }
        ss << std::endl;
    }

    return ss.str();
}


