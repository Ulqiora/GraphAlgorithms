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
    for (auto& row : data) {
        double min = row[0].second;
        for (auto& cell : row) {
            if (cell.second > min) min = (cell.second);
        }
        result->push_back(min);
    }
    return result;
}

}  // namespace s21