#include <iomanip>
#include <iostream>

#include "Model/GraphAlgorithms.h"
#include "Model/graph.h"
int main() {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/11.txt");
  GraphAlgorithm a1;
  TsmResult res=a1.solveTravelingSalesmanProblem(g1);
  std::cout<<res.distance<<'\n';
  for(auto& i:res.vertices)
    std::cout<<i<<' ';
  return 0;
}