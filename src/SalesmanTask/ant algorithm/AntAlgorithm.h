#pragma once
#include <vector>
#include "graph.h"
#include "../TsmResult.h"
#include "Ant.h"
namespace s21{

class AntAlgorithm{
    Graph* graph=nullptr;
    Matrix pheromoneMap;
    std::vector<Ant> ants;
    void initDateOfClass();
public:
    AntAlgorithm()=default;
    TsmResult start(Graph* graphTest);
private:
    const double startPheromone=0.33;
};


}