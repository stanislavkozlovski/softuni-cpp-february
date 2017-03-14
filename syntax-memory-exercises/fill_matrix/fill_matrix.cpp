#include <iostream>
#include <deque>
#include <tuple>

char** buildMatrix(int row, int col);
void fillMatrix(char** matrix, int startRow, int startCol, char newSymbol, int rowCount, int colCount); 
bool isInBounds(int row, int maxRow);
void printMatrix(char** matrix, int rowCount, int colCount);

int main() {
    int r, c, startRow, startCol;
    char newSymbol;
    std::cin >> r >> c;
    char** matrix = buildMatrix(r, c);
    std::cin >> newSymbol >> startRow >> startCol;
    fillMatrix(matrix, startRow, startCol, newSymbol, r, c);
    printMatrix(matrix, r, c);
    return 0;
}

void fillMatrix(char** matrix, int startRow, int startCol, char newSymbol, int rowCount, int colCount) {
    std::deque<std::tuple<int, int>> stack;
    char originalElement = matrix[startRow][startCol];
    stack.push_back(std::make_tuple(startRow, startCol));
    while (!stack.empty()) {
        int currentRow, currentCol;
        std::tie(currentRow, currentCol) = stack.front();
        stack.pop_front();
        
        matrix[currentRow][currentCol] = newSymbol;
        if ((currentRow + 1 < rowCount) && matrix[currentRow+1][currentCol] == originalElement) {
            // go up
            stack.push_back(std::make_tuple(currentRow+1, currentCol));
        }
        if ((currentRow - 1 >= 0) && matrix[currentRow-1][currentCol] == originalElement) {
            // go down
            stack.push_back(std::make_tuple(currentRow-1, currentCol));
        }
        if ((currentCol + 1 < colCount) && matrix[currentRow][currentCol + 1] == originalElement) {
            // go right
            stack.push_back(std::make_tuple(currentRow, currentCol + 1));
        }
        if ((currentCol - 1 >= 0) && matrix[currentRow][currentCol - 1] == originalElement) {
            // go left
            stack.push_back(std::make_tuple(currentRow, currentCol - 1));
        }
    }
}

void printMatrix(char** matrix, int rowCount, int colCount) {
    for (size_t i = 0; i < rowCount; i++) {
        for (size_t j = 0; j < colCount; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

bool isInBounds(int row, int maxRow) {
    return row < maxRow && row >= 0;
}

char** buildMatrix(int row, int col) {
   char** matrix = new char*[row];
    for (size_t i = 0; i < row; i++) {
        matrix[i] = new char[col];
        for (size_t j = 0; j < col; j++) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}