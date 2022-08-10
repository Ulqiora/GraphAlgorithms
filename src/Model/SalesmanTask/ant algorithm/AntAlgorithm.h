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
  const int numOfIteration = 30;

  void initPheromonesMap(){
    pheromoneMap.setSize(graph->size());
    for(int i=0;i<pheromoneMap.size();++i){
      for(int j=0;j<pheromoneMap.size();++j){
        pheromoneMap(i,j)=startPheromone;
      }
    }
  }

 public:
  AntAlgorithm() = default;
  TsmResult start(Graph* graphTest){
    if(!graphTest) throw std::invalid_argument("This graph is empty");
    graph=graphTest;
    initPheromonesMap();
    for(int numOfIteration=graph->size();numOfIteration;--numOfIteration){
      
    }
  }

 private:
  const double startPheromone = 0.33;
};

}  // namespace s21