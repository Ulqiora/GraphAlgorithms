#pragma once
#include <algorithm>
#include <list>
#include <vector>

#include "../TsmResult.h"
#include "Ant.h"
#include "../../graph.h"
namespace s21 {

class AntAlgorithm {
    Graph* graph = nullptr;
    Matrix pheromoneMap;
    std::vector<Ant> ants;
    const int numOfIteration = 30;
    const int evaporationCoef = 0.5;
    void initPheromonesMap();

    void updatePheromoneMap();
    void updateTsmResult(TsmResult* result,int& numOfIteration);

    void createAnts();
    
   public:
    AntAlgorithm() = default;
    TsmResult start(Graph* graphTest);
   private:
    const double startPheromone = 0.33;
};

}  // namespace s21