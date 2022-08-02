#include "Matrix.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
namespace s21{
enum class TypeGraphByDirection{
    UNDIRECRED=0,
    DIRECTED
};

enum class TypeGraphByWeights{
    UNWEIGHTED=0,
    WEIGHTED
};

class Graph{
private:
    std::string name;
    Matrix adjacencyMatrix;
    TypeGraphByDirection  typeDirection;
    TypeGraphByWeights typeWeights;
    void initTypes();
    void printInfoAboutEdge(int firstNode, int secondNode, std::ofstream &file,const std::string& EdgesInFile,const Matrix& temp);
public:
    Graph(){}
    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
    int size(){return adjacencyMatrix.size();}
    double operator()(int i,int j){return adjacencyMatrix(i,j);}
};

}