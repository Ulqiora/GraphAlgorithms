#include <iomanip>
#include <iostream>
#include "Model/SalesmanTask/BnBAlgorithm/MatrixBnB.h"
// #include "Model/GraphAlgorithms.h"
// #include "Model/graph.h"
int main() {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/11.txt");
    MatrixBnB res(g1);
    res= res.createCopyWithoutEdge(0,0);
  for(auto& row:res){
    for(auto& cell: row){
      std::cout<<" w = "<<cell.second<<" | ";
    }
    std::cout<<'\n';
  }
  return 0;
}