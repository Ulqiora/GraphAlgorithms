#include <iomanip>
#include <iostream>
#include "Model/SalesmanTask/BnBAlgorithm/BnBAlgorithm.h"
// #include "Model/GraphAlgorithms.h"
// #include "Model/graph.h"
int main() {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/11.txt");
    BnBAlgorithm bb;
    TsmResult res=  bb.start(g1,1);
    for(auto   i:res.vertices) std::cout<<i<<' ';
    std::cout<<'\n'<<res.distance<<'\n';
  return 0;
}