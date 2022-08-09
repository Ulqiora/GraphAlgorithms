#include <iomanip>
#include <iostream>

#include "Model/GraphAlgorithms.h"
#include "Model/graph.h"
int main() {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/4.txt");
  // std::cout << "Type by direction:"
  //           << (static_cast<int>(g1.getTypeByDirection()) == 0 ?
  //           "UNDIRECTION"
  //                                                              :
  //                                                              "DIRECTION")
  //           << std::endl;
  // std::cout << "Type by weiths:"
  //           << (static_cast<int>(g1.getTypeByWeights()) == 0 ? "UNWEIGHTED"
  //                                                            : "WEIGHTED")
  //           << std::endl;
  // std::cout << "Has negative:" << static_cast<int>(g1.hasNegativeWeights())
  //           << std::endl;
  // std::cout << g1(0, 1) << std::endl;
  // g1.exportGraphToDot("../materials/graphs/5.dot");
  GraphAlgorithm al;
  std::vector<int> result = al.breadthFirstSearch(g1, 1);
  for (auto& i : result) {
    std::cout << i << ' ';
  }
  return 0;
}