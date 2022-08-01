#include "Matrix.h"
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
namespace s21{
enum class TypeGraphByDirection{
    UNDIRECRED=0,
    DIRECTED
};

enum class TypeGraphByWeights{
    UNWEIGHTED=0,
    WEIGHTED
};

class graph{
private:
    std::string name;
    Matrix adjacencyMatrix;
    TypeGraphByDirection  typeDirection;
    TypeGraphByWeights typeWeights;
    void initTypes();
    void printInfoAboutEdge(int firstNode, int secondNode, std::ofstream &file,const std::string& EdgesInFile,const Matrix& temp);
public:
    graph(){}
    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
};

}