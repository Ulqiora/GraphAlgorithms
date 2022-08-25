#include <gtest/gtest.h>

#include <string>

#include "../Model/GraphAlgorithms.h"

TEST(GraphAlgorithms, DFT) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/4.txt");
  GraphAlgorithms ga;
  s21::Matrix result = ga.getLeastSpanningTree(g1,1);
  MatrixBnB result2{{},{},{},{}};
  ASSERT_TRUE(result==result2);
}