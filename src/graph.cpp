#include "graph.h"
namespace s21 {

void graph::loadGraphFromFile(std::string filename) {
    try {
        typeDirection=TypeGraphByDirection::UNDIRECRED;
        typeWeights=TypeGraphByWeights::UNWEIGHTED;
        std::ifstream file(filename);
        std::string temp="";
        adjacencyMatrix.loadMatrix(file);
        initTypes();
    } catch(const std::exception& e){
        throw e;
    }
}

void graph::initTypes(){
    for(int i=0;i<adjacencyMatrix.size();++i){
        for(int j=0;j<adjacencyMatrix.size();++j){
            if(adjacencyMatrix(i,j)!=adjacencyMatrix(j,i))
                typeDirection=TypeGraphByDirection::DIRECTED;
            if(adjacencyMatrix(i,j)>1)
                typeWeights=TypeGraphByWeights::WEIGHTED;
        }
    }
}


void graph::exportGraphToDot(std::string filename) {
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
    int sizeMatrix = adjacencyMatrix.size();
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            printInfoAboutEdge(i + 1, j + 1, file,EdgesInFile,temp);
        }
    }
    file << "}";
    file.close();
}

void graph::printInfoAboutEdge(int firstNode, int secondNode, std::ofstream &file,const std::string& EdgesInFile,const Matrix& temp) {
    std::string first = std::to_string(firstNode);
    std::string second = std::to_string(secondNode);
    std::string weight = (typeWeights == TypeGraphByWeights::WEIGHTED) ? std::to_string(temp(firstNode-1, secondNode-1)) : "";
    if (temp(firstNode-1, secondNode-1) != 0) {
        if (temp(firstNode-1, secondNode-1) > 0) {
            file << "\t" << first << " " << EdgesInFile << " " << second << " [" << std::endl;
        } else {
            file << "\t" << second << " " << EdgesInFile << " " << first << " [" << std::endl;
        }
        file << "\t\tlabel = \"" << weight << "\"" << std::endl;
        file << "\t\tweight = \"" << weight << "\"" << std::endl;
        file << "\t];" << std::endl;
    }
}

}  // namespace s21