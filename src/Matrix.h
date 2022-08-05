#pragma once
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
namespace s21 {
class Matrix {
   private:
    int _size;
    double** matrixData;
    void allocateMemory();
    void freeMemory();
    void copyMatrixData(const Matrix& other);

   public:
    Matrix(int newSize);
    Matrix();
    Matrix(const Matrix& other);
    double& operator()(int i, int j) const { return matrixData[i][j]; }
    ~Matrix() { freeMemory(); }
    int size() const { return _size; }
    const Matrix& operator=(const Matrix& other);
    void setSize(int newNumOfRows);
    void loadMatrix(std::ifstream& file);
    void setValueForAll(double value);
};
}  // namespace s21