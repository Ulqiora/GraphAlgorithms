#pragma once
#include <vector>
#include <algorithm>
#include "../../graph.h"
#include "Index.h"
namespace s21 {

using Distance = double;
using Cell = std::pair<Index, Distance>;
using Vector = std::vector<Cell>;
using numLimD=std::numeric_limits<double>;
class MatrixBnB {
   private:
    std::vector<Vector> data;

   public:
    MatrixBnB():data(0){}
    MatrixBnB(const Graph& graph);
    auto rows(){return data.size();}
    auto cols(int numOfRow){return data[numOfRow].size();}
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    // MatrixBnB reducedRow(int row);
    // MatrixBnB reducedCol(int col);
    std::vector<double>* findMinimumInAllRows();
    std::vector<double>* findMinimumInAllCols();
    Cell& operator()(int i, int j) { return data[i][j]; }
};

}  // namespace s21