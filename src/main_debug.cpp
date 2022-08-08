#include <iomanip>
#include <iostream>

#include "Model/graph.h"

int main() {
  using namespace s21;
  Graph g1;
  try {
    Graph g1;
    g1.loadGraphFromFile("../src/Tests/Matrices/18_fail_size.txt");
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  // GraphAlgorithm al;
  // std::vector<int> result = al.depthFirstSearch(g1, 1);
  return 0;
}