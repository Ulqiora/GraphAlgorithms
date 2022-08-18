#include "MatrixBnB.h"

namespace s21 {
MatrixBnB::MatrixBnB(const Graph& graph) : data(graph.size()) {
    int i = 0;
    for (auto& row : data) {
        row.reserve(graph.size());
        for (int j = 0; j < graph.size(); ++j) {
            double value = (i != j) ? graph(i, j) : numLimD::infinity();
            row.push_back(std::make_pair<Index, Distance>(Index(i, j), Distance(value)));
        }
        ++i;
    }
}

std::vector<double>* MatrixBnB::findMinimumInAllRows() {
    std::vector<double>* result = new std::vector<double>();
    for (auto& row : data) {
        result->push_back((*std::min_element(row.begin(), row.end(), [](const Cell& t1, const Cell& t2) {
                              return t1.second < t2.second;
                          })).second);
    }
    return result;
}

std::vector<double>* MatrixBnB::findMinimumInAllCols() {
    std::vector<double>* result = new std::vector<double>();
    for (int col = 0; col < data.size(); ++col) {
        double min = data[0][col].second;
        for (int row = 0; row < data.size(); ++row) {
            if (data[row][col].second < min) min = (data[row][col].second);
        }
        result->push_back(min);
    }
    return result;
}



double MatrixBnB::reducedRowsAndCalcMinimums()
{
    std::vector<double>* minimums = findMinimumInAllRows();
    int i=0;
    for(auto& row:data){
        for(auto& cell: row){
            cell.second-=(*minimums)[i];
        }
        i++;
    }
    double result=0.0;
    for(auto& min:(*minimums)) result+=min;
    delete minimums;
    return result;
}

double MatrixBnB::reducedColsAndCalcMinimums()
{
    std::vector<double>* minimums = findMinimumInAllCols();
    for(int col=0;col<data.size();++col){
        for(int row=0; row<data.size();++row){
            data[row][col].second-=(*minimums)[col];
        }
    }
    double result=0.0;
    for(auto& min:(*minimums)) result+=min;
    delete minimums;
    return result;
}

MatrixBnB MatrixBnB::createCopyWithoutEdge(int indexFVert,int indexSVert)
{
    MatrixBnB result(*this);
    for(int i=0;i<data.size();++i){
        for(int j=0;j<data.size();++j){
            if (i == indexFVert || j == indexSVert) result(i, j).second = numLimD::infinity();
        }
    }
    return result;
}


}  // namespace s21