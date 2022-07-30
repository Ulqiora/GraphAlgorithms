#include "graph.h"
namespace s21{


void graph::loadGraphFromFile(std::string filename)
{
    std::ifstream file(filename);

}

void graph::exportGraphToDot(std::string filename)
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Invalid name file!");
    }
    std::string EdgesInFile = "--";
    if (typeDirection == TypeGraphByDirection::DIRECTED) {
        file << "digraph {" << std::endl;
        EdgesInFile = "->";
    } else {
        file << "graph {" << std::endl;
    }
    Matrix temp = adjacencyMatrix;
    int sizeMatrix=adjacencyMatrix.size();
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            int one = i + 1, two = j + 1;
            std::string numberOne = std::to_string(one);
            std::string numberTwo = std::to_string(two);
            std::string weight = (typeWeights==TypeGraphByWeights::WEIGHTED)?std::to_string(temp(i,j)):"";
            if (temp(i, j) != 0) {
                if (temp(i, j) > 0) {
                    file << "\t" << numberOne << " " << EdgesInFile << " " << numberTwo << " [" << std::endl;
                } else {
                    file << "\t" << numberTwo << " " << EdgesInFile << " " << numberOne << " [" << std::endl;
                }
                file << "\t\tlabel = \"" << weight << "\"" << std::endl;
                file << "\t\tweight = \"" << weight << "\"" << std::endl;
                file << "\t];" << std::endl;
                temp(j, i)=temp(j, i)?
            }
        }
    }
    file << "}";
    file.close();
}


}