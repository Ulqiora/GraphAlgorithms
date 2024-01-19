#include <Graph/BnBAlgorithm/MatrixBnB.h>
namespace s21 {
MatrixBnB::MatrixBnB(const Graph& graph) : data(graph.size()) {
    int i = 0;
    for (auto& row : data) {
        row.reserve(graph.size());
        for (int j = 0; j < graph.size(); ++j) {
            double value = (i != j) ? graph(i, j) : numLimD::infinity();
            row.push_back(Cell(value));
        }
        ++i;
    }
}

std::vector<double>* MatrixBnB::findMinimumInAllRows() {
    std::vector<double>* result = new std::vector<double>();
    for (auto& row : data) {
        double min = numLimD::infinity();
        for (int i = 0; i < data.size(); ++i) {
            if (row[i] < min){ min = row[i];
            }
        }
        min=(min==numLimD::infinity()?0:min);
        result->push_back(min);
    }
    return result;
}

std::vector<double>* MatrixBnB::findMinimumInAllCols() {
    std::vector<double>* result = new std::vector<double>();
    for (int col = 0; col < data.size(); ++col) {
        double min = data[0][col];
        for (int row = 0; row < data.size(); ++row) {
            if (data[row][col] < min) min = data[row][col];
        }
        min=(min==numLimD::infinity()?0:min);
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
            cell-=((*minimums)[i]==numLimD::infinity()?0:(*minimums)[i]);
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
            data[row][col]-=((*minimums)[col]==numLimD::infinity()?0:(*minimums)[col]);
        }
    }
    double result=0.0;
    for(auto& min:(*minimums)) result+=min;
    delete minimums;
    return result;
}

MatrixBnB MatrixBnB::createCopyWithoutEdge(int indexFVert,int indexSVert)const 
{
    MatrixBnB result(*this);
    for(int i=0;i<data.size();++i){
        for(int j=0;j<data.size();++j){
            if (i == indexFVert || j == indexSVert) result(i, j) = numLimD::infinity();
        }
    }
    result(indexSVert, indexFVert) = numLimD::infinity();
    return result;
}


}  // namespace s21