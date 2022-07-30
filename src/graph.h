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
    std::map<std::string,int> namesOfNode;
    void printInfoAboutEdge(int firstNode, int secondNode, std::ofstream &file,const std::string& EdgesInFile,const Matrix& temp);
    void getTypeByDirectionAndName(std::ifstream& file);
    void parseLine(bool& name,std::stringstream& ss);
public:
    graph(){}
    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
};

}