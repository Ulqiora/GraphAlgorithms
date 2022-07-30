#include "graph.h"
namespace s21 {

void graph::loadGraphFromFile(std::string filename) {
    namesOfNode.clear();
    adjacencyMatrix.setSize(0);
    std::ifstream file(filename);
    if (!file.is_open()) throw std::invalid_argument("Invalid name file!");
    getTypeByDirectionAndName(file);
    std::string lineFile;
    std::stringstream ss;
    bool name = true;
    while (std::getline(file, lineFile)) {
        ss.clear();
        ss.str(lineFile);
    }
}

void graph::parseLine(bool &name, std::stringstream &ss) {
    std::string token, prev;
    ss >> token;
    while (token.back() != ';') {
        if (name) {
            namesOfNode.insert(std::make_pair(token, namesOfNode.size()));
            adjacencyMatrix(namesOfNode[token],namesOfNode[prev])=1;
            prev=token;
        } else if ((token == "->" && typeDirection == TypeGraphByDirection::DIRECTED) ||
                   (token == "--" && typeDirection == TypeGraphByDirection::UNDIRECRED)) {
        }
        name = !name;
    }
}

void graph::getTypeByDirectionAndName(std::ifstream &file) {
    std::string temp;
    file >> temp;
    if (temp == "graph")
        typeDirection = TypeGraphByDirection::UNDIRECRED;
    else if (temp == "digraph")
        typeDirection = TypeGraphByDirection::DIRECTED;
    else
        throw std::invalid_argument(temp + " - undefined words");
    file >> name >> temp;
    if (temp != "{") throw std::invalid_argument("symbol '{' not founded");
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
    std::string weight = (typeWeights == TypeGraphByWeights::WEIGHTED) ? std::to_string(temp(i, j)) : "";
    if (temp(i, j) != 0) {
        if (temp(i, j) > 0) {
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