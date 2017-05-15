#include "Matrix.h"

Matrix::~Matrix() {
    this->freeRowsCols(this->data, this->rows);
}

Matrix::Matrix(unsigned int rows, unsigned int columns) : rows(rows), columns(columns){
    this->data = new Row[rows];
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new DataType[columns];
        for (int j = 0; j < columns; ++j) {
            this->data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &other) {
    this->data = new Row[other.rows];
    for (int i = 0; i < other.rows; ++i) {
        this->data[i] = new DataType[other.columns];
        for (int j = 0; j < other.columns; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }
    this->rows = other.rows;
    this->columns = other.columns;
}

unsigned int Matrix::getRows() const {
    return this->rows;
}

unsigned int Matrix::getColumns() const {
    return this->columns;
}

DataType Matrix::get(unsigned int row, unsigned int column) const {
    this->ensureInBounds(row, column);
    return this->data[row][column];
}

void Matrix::changeSize(unsigned int rows, unsigned int columns) {
    auto tempBoard = new Row[rows];
    for (int i = 0; i < rows; ++i) {
        tempBoard[i] = new DataType[columns];
        for (int j = 0; j < columns; ++j) {
            tempBoard[i][j] = 0;
        }
    }

    for (int i = 0; i < this->rows; ++i) {
        if (i >= rows) {
            break;
        }
        for (int j = 0; j < this->columns; ++j) {
            if (j >= columns) {
                break;
            }

            tempBoard[i][j] = this->data[i][j];
        }
    }
    // Delete old board
    this->freeRowsCols(this->data, this->rows);

    this->rows = rows;
    this->columns = columns;
    this->data = tempBoard;
}

void Matrix::set(unsigned int row, unsigned int column, DataType value) {
    this->ensureInBounds(row, column);
    this->data[row][column] = value;
}

Matrix &Matrix::operator=(const Matrix &other) {
    // Delete self
    this->freeRowsCols(this->data, this->rows);

    if (other.rows <= 0 || other.columns <= 0) {
        this->rows = other.rows;
        this->columns = other.columns;
        this->data = nullptr;
//        return m;
    }
    this->data = new Row[other.rows];
    for (int i = 0; i < other.rows; ++i) {
        this->data[i] = new DataType[columns];

        for (int j = 0; j < other.columns; ++j) {
            this->data[i][j] = other.data[i][j];
        }
    }
    this->rows = other.rows;
    this->columns = other.columns;
    // TODO: Delete other ??

//    return *this;
}

std::string Matrix::toString() const {
    std::stringstream ss;
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            if (j == this->columns-1) {  // last el, no space
                ss << this->data[i][j];
            } else {
                ss << this->data[i][j] << " ";
            }
        }

        ss << std::endl;
    }

    return ss.str();
}

void Matrix::ensureInBounds(unsigned int row, unsigned int column) const {
    if (row < 0 || row >= this->rows || column < 0 || column >= this->columns) {
        throw std::range_error("Out of bounds");
    }
}

void Matrix::freeRowsCols(RowsCols data, unsigned int rows) {
    if (rows <= 0 || data == NULL || data[0] == NULL) {
        delete data;
        return;
    }
    for (int i = 0; i < rows; ++i) {
        delete data[i];
    }
    delete data; // TODO: ?
}

RowsCols Matrix::initRowsCols(unsigned int rows, unsigned int columns) {
    return NULL;
}

void Matrix::copyData(RowsCols source, unsigned int sourceRows, unsigned int sourceColumns, RowsCols dest,
                      unsigned int destRows, unsigned int destColumns) {


      for (int i = 0; i < sourceRows; ++i) {
        if (i >= destRows) {
            break;
        }
        for (int j = 0; j < sourceColumns; ++j) {
            if (j >= destColumns) {
                break;
            }

            dest[i][j] = source[i][j];
        }
    }
}
