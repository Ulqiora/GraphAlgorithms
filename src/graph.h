#include "Matrix.h"

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
    Matrix adjacencyMatrix;
    TypeGraphByDirection  typeDirection;
    TypeGraphByWeights typeWeights;
public:
    graph(){}
    void loadGraphFromFile(std::string filename);
    void exportGraphToDot(std::string filename);
};

}