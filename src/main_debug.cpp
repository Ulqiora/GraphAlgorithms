#include <iomanip>
#include <iostream>

#include "Model/graph.h"
#include "Model/GraphAlgorithms.h"

int main() {
  using namespace s21;
  // Graph g1;
  // g1.loadGraphFromFile("/Users/jcraster/GraphAlgorithms/matrices/1.txt");
  // for (int i = 0; i < g1.size(); i++) {
  //   for (int j = 0; j < g1.size(); j++) {
  //     std::cout << g1(i, j) << ' ';
  //   }
  //   std::cout << std::endl;
  // }
  // g1.exportGraphToDot("/Users/jcraster/GraphAlgorithms/matrices/2.dot");
  
  Graph myG;
  myG.loadGraphFromFile("/Users/cojess/GraphAlgorithms/materials/matrices/18.txt");
  GraphAlgorithm algo;
  // int res = algo.getShortestPathBetweenVertices(myG, 2, 9);
  // std::cout << "res = " << res << std::endl;

  std::vector<int> res = algo.depthFirstSearch(myG, 1);

  for (unsigned int i = 0; i < res.size(); i++) {
  std::cout << res.data()[i] << " ";
  }
  // std::cout << std::endl;

  return 0;
}