#pragma once

#include <vector>
#include <string>
#include <sstream>
#include "smart_array.cpp"

using std::vector;
using std::string;
using std::stringstream;


class SmartMatrix {
    private:
        vector<SmartArray> matrix;
    public:
        SmartMatrix(int rows, int cols) {
            for (int i = 0; i < rows; i++) {
                matrix.push_back(SmartArray(cols));
            }
        }

        SmartArray& operator[](const int row) {
            return this->matrix[row];
        }

        string toString() {
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
};
