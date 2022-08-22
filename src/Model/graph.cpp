#include "graph.h"
namespace s21 {

void Graph::loadGraphFromFile(std::string filename) {
    try {
        typeDirection = TypeGraphByDirection::UNDIRECRED;
        typeWeights = TypeGraphByWeights::UNWEIGHTED;
        positiveWeights = true;
        std::ifstream file(filename);
        if (!file.is_open()) throw std::invalid_argument("File can't be opened");
        adjacencyMatrix.loadMatrix(file);
        initTypes();
    } catch (std::exception& e) {
        throw;
    }
}

void Graph::initTypes() {
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = 0; j < adjacencyMatrix.size(); ++j) {
            if (std::fabs(adjacencyMatrix(i, j) - adjacencyMatrix(j, i)) >
                std::numeric_limits<double>::epsilon())
                typeDirection = TypeGraphByDirection::DIRECTED;

            if (std::fabs(adjacencyMatrix(i, j)) > std::numeric_limits<double>::epsilon()) {
                if ((std::fabs(adjacencyMatrix(i, j) - 1.0) > std::numeric_limits<double>::epsilon()))
                    typeWeights = TypeGraphByWeights::WEIGHTED;
            } else if (adjacencyMatrix(i, j) < 0)
                positiveWeights = false;
        }
    }
}

void Graph::exportGraphToDot(std::string filename) {
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
        for (int j = (typeDirection == TypeGraphByDirection::UNDIRECRED ? i : 0); j < sizeMatrix; j++) {
            printInfoAboutEdge(i + 1, j + 1, file, EdgesInFile, temp);
        }
    }
    file << "}";
    file.close();
}

void Graph::printInfoAboutEdge(int firstNode, int secondNode, std::ofstream& file,
                               const std::string& EdgesInFile, const Matrix& temp) {
    std::string first = std::to_string(firstNode);
    std::string second = std::to_string(secondNode);
    std::string weight = (typeWeights == TypeGraphByWeights::WEIGHTED)
                             ? std::to_string(temp(firstNode - 1, secondNode - 1))
                             : "";
    if (std ::fabs(temp(firstNode - 1, secondNode - 1)) > std::numeric_limits<double>::epsilon()) {
        if (temp(firstNode - 1, secondNode - 1) > std::numeric_limits<double>::epsilon()) {
            file << "\t" << first << " " << EdgesInFile << " " << second << " [" << std::endl;
        } else {
            file << "\t" << second << " " << EdgesInFile << " " << first << " [" << std::endl;
        }
        file << "\t\tlabel = \"" << weight << "\"" << std::endl;
        file << "\t\tweight = \"" << weight << "\"" << std::endl;
        file << "\t];" << std::endl;
    }
}

bool Graph::isCompliteGraph() {
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        for (int j = i; j < adjacencyMatrix.size(); ++j) {
            if (std::fabs(adjacencyMatrix(i, j) - adjacencyMatrix(j, i)) >
                    std::numeric_limits<double>::epsilon() &&
                (adjacencyMatrix(i, j) > 0)) {
                return false;
            }
        }
    }
    return true;
}

}  // namespace s21