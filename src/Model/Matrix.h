#pragma once
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <limits>
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
  bool operator==(const Matrix& other);
  void setSize(int newNumOfRows);
  void loadMatrix(std::ifstream& file);
  void setValueForAll(double value);
  void mul_number(const double num);
  Matrix& operator*=(const double value);
};
}  // namespace s21