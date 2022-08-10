#include <gtest/gtest.h>

#include <string>

#include "../Model/GraphAlgorithms.h"

TEST(GraphAlgorithms, DFT) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/4.txt");
  GraphAlgorithm ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  std::vector<int> result2;
  result2.push_back(1);
  result2.push_back(2);
  result2.push_back(4);
  result2.push_back(3);
  ASSERT_TRUE(result==result2);
}

TEST(GraphAlgorithms, DFT2) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/5.txt");
  GraphAlgorithm ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  std::vector<int> result2;
  result2.push_back(1);
  result2.push_back(2);
  result2.push_back(3);
  result2.push_back(5);
  result2.push_back(4);
  ASSERT_TRUE(result==result2);
}
TEST(GraphAlgorithms, DFT3) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/18.txt");
  GraphAlgorithm ga;
  std::vector<int> result = ga.depthFirstSearch(g1,1);
  // std::vector<int> result2{};
  // ASSERT_TRUE(result==result2);
  for(auto&i : result)
    std::cout<<i<<' ';
}