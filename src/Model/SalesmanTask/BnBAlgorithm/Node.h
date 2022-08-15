#pragma once 
#include <vector>
#include "MatrixBnB.h"
namespace s21 {


namespace matrixBnB{
    MatrixBnB createMatrixBnB(const Graph& other);
}

struct Node {
    MatrixBnB matrix;
    double lowerBound = 0;
    std::vector<Index> path;
    std::vector<Node> children;
    Node(MatrixBnB matrixNew, double lowerBoundNew, std::vector<Index> pathNew)
        : matrix(matrixNew), lowerBound(lowerBoundNew), path(pathNew) {}
    Node(const Node& other) : matrix(other.matrix), lowerBound(other.lowerBound), path(other.path) {}
};
}  // namespace s21