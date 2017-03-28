#pragma once
#include <string>
#include <vector>

class SmartMatrix {
private:
    vector<SmartArray> matrix;
public:
    SmartMatrix(int rows, int cols);
    SmartArray& operator[](const int row);
    string toString();
};

