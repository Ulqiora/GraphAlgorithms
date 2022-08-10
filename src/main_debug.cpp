#include <iomanip>
#include <iostream>

#include "Model/GraphAlgorithms.h"
#include "Model/graph.h"
int main() {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/18.txt");
  GraphAlgorithm al;
  std::vector<int> result = al.depthFirstSearch(g1, 1);
  for (auto& i : result) {
    std::cout << i << ' ';
  }
  return 0;
}