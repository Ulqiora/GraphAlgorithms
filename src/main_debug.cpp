#include <iomanip>
#include <iostream>
// #include "Model/SalesmanTask/BnBAlgorithm/BnBAlgorithm.h"
// #include "Model/GraphAlgorithms.h"
// #include "Model/graph.h"
#include "View/ConsoleView.h"
int main() {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/18.txt");
  GraphAlgorithms  ga;
  std::cout<<ga.getShortestPathBetweenVertices(g1,1,6);
  // s21::ConsoleView con;
  return 0;
}