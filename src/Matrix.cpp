#include "Matrix.h"

namespace s21 {
void Matrix::allocateMemory() {
    matrixData = new double*[numOfRows];
    for (int i = 0; i < numOfRows; ++i) {
        matrixData[i] = new double[numOfCols]();
    }
}
void Matrix::freeMemory() {
    for (int i = 0; i < numOfRows; ++i) {
        delete[] matrixData[i];
    }
    delete[] matrixData;
}

Matrix::Matrix() {
    numOfCols = numOfRows = 0;
    matrixData = nullptr;
}


Matrix::Matrix(const Matrix& other): numOfCols(other.numOfCols),numOfRows(other.numOfRows)
{
    copyMatrixData(other);
}


Matrix::Matrix(int rows, int cols) : numOfCols(cols), numOfRows(rows) {
    if (rows < 1 || cols < 1) throw std::exception("alo");
    allocateMemory();
}

void Matrix::setCols(int newNumOfCols) {
    if(newNumOfCols<1)
        throw std::invalid_argument("first argument < 1");
    Matrix copy(*this);
    freeMemory();
    numOfCols=newNumOfCols;
    allocateMemory();
    copyMatrixData(copy);
}

void Matrix::setRows(int newNumOfRows) {
    if(newNumOfRows<1)
        throw std::invalid_argument("first argument < 1");
    Matrix copy(*this);
    freeMemory();
    numOfCols=newNumOfRows;
    allocateMemory();
    copyMatrixData(copy);
}

void Matrix::copyMatrixData(const Matrix& other) {
    int minimumNumOfRows=numOfRows<other.numOfRows?numOfRows:other.numOfRows;
    int minimumNumOfCols=numOfCols<other.numOfCols?numOfCols:other.numOfCols;
    for (int i = 0; i < minimumNumOfRows; ++i) {
        for (int j = 0; j < minimumNumOfCols; ++j) {
            matrixData[i][j] = other.matrixData[i][j];
        }
    }
}

const Matrix& Matrix::operator=(const Matrix& other) {
    if (&other == this) return other;
    if (!(other.numOfCols == other.numOfRows && numOfRows==other.numOfRows)) {
        freeMemory();
        numOfCols=other.numOfCols;
        numOfRows=other.numOfRows;
        allocateMemory();
    }
    copyMatrixData(other);
    return other;
}

}  // namespace s21