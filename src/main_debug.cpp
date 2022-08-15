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
    std::vector<double> *out=res.findMinimumInAllRows();
    for(auto& i:(*out)){
      std::cout<<i<<' ';
    }
    delete out;
  // std::cout<<"num of rows:"<<matrixAdj.rows()<<'\n';
  // for(auto& row:matrixAdj){
  //   std::cout<<"num of cols:"<<matrixAdj.cols(0)<<'\n';
  //   for(auto& cell: row){
  //     std::cout<<"i = "<<cell.first.row<<", j = "<<cell.first.col<<", w = "<<cell.second<<" | ";
  //   }
  //   std::cout<<'\n';
  // }
  return 0;
}