#include <iostream>

#include "Model/GraphAlgorithms.h"

int main() {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("/Users/jcraster/GraphAlgorithms/matrices/1.txt");
  for (int i = 0; i < g1.size(); i++) {
    for (int j = 0; j < g1.size(); j++) {
      std::cout << g1(i, j) << ' ';
    }
    std::cout << std::endl;
  }
  g1.exportGraphToDot("/Users/jcraster/GraphAlgorithms/matrices/2.dot");
  return 0;
}