#include "Matrix.h"

namespace s21 {
void Matrix::allocateMemory() {
    matrixData = new double*[_size];
    for (int i = 0; i < _size; ++i) {
        matrixData[i] = new double[_size]();
    }
}
void Matrix::freeMemory() {
    for (int i = 0; i < _size; ++i) {
        delete[] matrixData[i];
    }
    delete[] matrixData;
}

Matrix::Matrix() {
    _size = 0;
    matrixData = nullptr;
}

Matrix::Matrix(const Matrix& other) : _size(other._size) { copyMatrixData(other); }

Matrix::Matrix(int newSize) : _size(newSize),matrixData(nullptr) {
    if (_size<1) throw std::exception("alo");
    allocateMemory();
}

void Matrix::setSize(int newSize) {
    if (newSize < 1) throw std::invalid_argument("first argument < 1");
    if (newSize==_size) return ;
    Matrix copy(*this);
    freeMemory();
    _size = newSize;
    allocateMemory();
    copyMatrixData(copy);
}

void Matrix::copyMatrixData(const Matrix& other) {
    int minimumSize = _size < other._size ? _size : other._size;
    for (int i = 0; i < minimumSize; ++i) {
        for (int j = 0; j < minimumSize; ++j) {
            matrixData[i][j] = other.matrixData[i][j];
        }
    }
}

const Matrix& Matrix::operator=(const Matrix& other) {
    if (&other == this) return other;
    if (!(other._size == other._size)) {
        freeMemory();
        _size = other._size;
        allocateMemory();
    }
    copyMatrixData(other);
    return other;
}


void Matrix::loadMatrix(std::ifstream& file)
{
    std::string temp="";
    file>>temp;
    if(isdigit(temp[0])&&temp[0]!='-')
        _size=std::stoi(temp);
    else 
        throw std::invalid_argument("");
    for(int i=0;i<_size;i++){
        for(int j=0;j<_size;j++){
            file>>temp;
            if(isdigit(temp[0])&&temp[0]!='-')
                matrixData[i][j]=std::stod(temp);
            else 
                throw std::invalid_argument("");
        }
    }
}


}  // namespace s21