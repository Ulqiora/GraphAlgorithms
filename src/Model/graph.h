#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Matrix.h"
namespace s21 {
enum class TypeGraphByDirection { UNDIRECRED = 0, DIRECTED };

enum class TypeGraphByWeights { UNWEIGHTED = 0, WEIGHTED };

class Graph {
   private:
    std::string name;
    Matrix adjacencyMatrix;
    TypeGraphByDirection typeDirection;
    TypeGraphByWeights typeWeights;
    bool positiveWeights = true;
    void initTypes();
    void printInfoAboutEdge(int firstNode, int secondNode, std::ofstream& file,
                            const std::string& EdgesInFile, const Matrix& temp);

   public:
    Graph() {}
    Graph(int size) : adjacencyMatrix(size) {}
    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
    int size() const { return adjacencyMatrix.size(); }
    double operator()(int i, int j) const { return adjacencyMatrix(i, j); }
    void setValue(int i, int j, double value) { adjacencyMatrix(i, j) = value; }
    TypeGraphByDirection getTypeByDirection() { return typeDirection; }
    TypeGraphByWeights getTypeByWeights() { return typeWeights; }
    bool hasNegativeWeights() { return !positiveWeights; }
    bool operator==(const Graph& other) { return adjacencyMatrix == other.adjacencyMatrix; }
    bool isCompliteGraph() {
        for (int i = 0; i < adjacencyMatrix.size(); ++i) {
            for (int j = i; j < adjacencyMatrix.size(); ++j) {
                if (std::fabs(adjacencyMatrix(i, j) - adjacencyMatrix(j, i)) >
                    std::numeric_limits<double>::epsilon()&&(adjacencyMatrix(i, j)>0)) {
                    return false;
                }
            }
        }
        return true;
    }
};

}  // namespace s21