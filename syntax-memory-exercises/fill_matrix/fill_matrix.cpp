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

void fillMatrix(char** matrix, int currentRow, int currentCol, char newSymbol, int rowCount, int colCount) {
    char originalElement = matrix[currentRow][currentCol];
    
    matrix[currentRow][currentCol] = newSymbol;

    if ((currentRow + 1 < rowCount) && matrix[currentRow+1][currentCol] == originalElement) {
        // go up
        fillMatrix(matrix, currentRow+1, currentCol, newSymbol, rowCount, colCount);
    }
    if ((currentRow - 1 >= 0) && matrix[currentRow-1][currentCol] == originalElement) {
        // go down
        fillMatrix(matrix, currentRow-1, currentCol, newSymbol, rowCount, colCount);
    }
    if ((currentCol + 1 < colCount) && matrix[currentRow][currentCol + 1] == originalElement) {
        // go right
        fillMatrix(matrix, currentRow, currentCol + 1, newSymbol, rowCount, colCount);
    }
    if ((currentCol - 1 >= 0) && matrix[currentRow][currentCol - 1] == originalElement) {
        // go left
        fillMatrix(matrix, currentRow, currentCol - 1, newSymbol, rowCount, colCount);
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