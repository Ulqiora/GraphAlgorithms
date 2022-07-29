#pragma once 
#include <exception>
#include <iostream>
namespace s21{
class Matrix{
private:
    unsigned int numOfCols,numOfRows;
    double** matrixData;
    void allocateMemory();
    void freeMemory();
    void copyMatrixData(const Matrix&  other);
public:
    Matrix(int rows, int cols);
    Matrix();
    Matrix(const Matrix& other);
    double& operator()(int i,int j)const{
        return matrixData[i][j];
    }
    ~Matrix(){
        freeMemory();
    }
    int cols(){
        return numOfCols;
    }
    int rows(){
        return numOfRows;
    }
    const Matrix& operator=(const Matrix&  other);
    void setRows(int newNumOfRows);
    void setCols(int newNumOfCols);
};
}