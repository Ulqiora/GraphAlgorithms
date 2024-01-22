#pragma once
#include <Graph/graph.h>
#include <algorithm>
#include <initializer_list>
#include <vector>

namespace s21 {

using Cell = double;
using Vector = std::vector<Cell>;
using numLimD = std::numeric_limits<double>;
class MatrixBnB {
   private:
    std::vector<Vector> data;
   public:
    std::vector<double>* findMinimumInAllRows();
    std::vector<double>* findMinimumInAllCols();
    MatrixBnB(std::initializer_list<std::initializer_list<double>>&& other):data(other.size()){
        int i=0;
        for(auto& row:other){
            data.reserve(other.size());
            for(auto& cell: row){
                data[i].push_back(cell);
            }
            i++;
        }
    }
    MatrixBnB():data(0){}
    MatrixBnB(const Graph& graph);
    auto rows(){return data.size();}
    auto cols(int numOfRow){return data[numOfRow].size();}
    [[nodiscard]] auto begin() const { return data.begin(); }
    [[nodiscard]] auto end() const { return data.end(); }
    [[nodiscard]] size_t size()const{ return data.size();}
    double reducedRowsAndCalcMinimums();
    double reducedColsAndCalcMinimums();
    [[nodiscard]] MatrixBnB createCopyWithoutEdge(size_t indexFVert,size_t indexSVert)const;
    Cell& operator()(int i, int j) { return data[i][j]; }
    Cell operator()(int i, int j) const { return data[i][j]; }

};

}  // namespace s21