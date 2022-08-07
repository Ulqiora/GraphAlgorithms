#pragma once
#include <vector>

#include "../TsmResult.h"
#include "Ant.h"
#include "graph.h"
namespace s21 {

class AntAlgorithm {
  Graph* graph = nullptr;
  Matrix pheromoneMap;
  std::vector<Ant> ants;
  void initDateOfClass();
  const int numOfIteration = 30;

 public:
  AntAlgorithm() = default;
  TsmResult start(Graph* graphTest);

 private:
  const double startPheromone = 0.33;
};

}  // namespace s21