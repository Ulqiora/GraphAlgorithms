#include <gtest/gtest.h>

#include <string>

#include "../Model/GraphAlgorithms.h"

TEST(GraphAlgorithms, DFT) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/4.txt");
  GraphAlgorithms ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  std::vector<int> result2{1,2,4,3};
  std::cout<<result.size()<<' '<<result2.size()<<'\n';
  // for(auto&i : result)
  //   std::cout<<i<<' ';
  // std::cout<<'\n';
  // for(auto&i : result2)
  //   std::cout<<i<<' ';
  ASSERT_TRUE(result==result2);
}

TEST(GraphAlgorithms, DFT2) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/5.txt");
  GraphAlgorithms ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  std::vector<int> result2{1,2,3,5,4};
  ASSERT_TRUE(result==result2);
}
TEST(GraphAlgorithms, DFT3) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/18.txt");
  GraphAlgorithms ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  std::vector<int> result2{1,2,5,9,14,3,6,11,7,12,17,18,10,15,16};
}