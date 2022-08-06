#include "AntAlgorithm.h"

namespace s21 {

TsmResult AntAlgorithm::start(Graph* graphTest) {
    if (graphTest->hasNegativeWeights() ||
        graphTest->getTypeByDirection() == TypeGraphByDirection::UNDIRECRED)
        throw std::invalid_argument("This graph has negative weights!");
    graph = graphTest;
    initDateOfClass();
}

void AntAlgorithm::initDateOfClass() {
    ants.clear();
    pheromoneMap = Matrix(graph->size());
    for (int i = 0; i < ants.size(); ++i) {
        for (int j = 0; j < ants.size(); ++j) {
            if ((*graph)(i, j) != 0) pheromoneMap(i, j) = startPheromone;
        }
    }
}

}  // namespace s21