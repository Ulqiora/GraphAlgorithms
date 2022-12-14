#include <gtest/gtest.h>

#include <string>

#include "../Model/graph.h"

TEST(Graph, LoadMatricesCorrectRead) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../materials/matrices/18.txt");
  Graph g2(g1.size());
  g2.setValue(0, 1, 15);
  g2.setValue(0, 2, 55);
  g2.setValue(0, 9, 34);
  g2.setValue(1, 4, 34);
  g2.setValue(2, 5, 12);
  g2.setValue(2, 6, 34);
  g2.setValue(3, 7, 44);
  g2.setValue(3, 8, 12);
  g2.setValue(3, 13, 334);
  g2.setValue(4, 8, 23);
  g2.setValue(5, 8, 34);
  g2.setValue(5, 10, 5);
  g2.setValue(6, 10, 32);
  g2.setValue(6, 11, 45);
  g2.setValue(7, 12, 33);
  g2.setValue(7, 13, 45);
  g2.setValue(8, 13, 43);
  g2.setValue(9, 14, 78);
  g2.setValue(9, 15, 6);
  g2.setValue(11, 16, 72);
  g2.setValue(11, 17, 34);
  ASSERT_TRUE(g1 == g2);
}

TEST(Graph, LoadMatrices_CheckCorrectPath) {
  using namespace s21;
  ASSERT_ANY_THROW({
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/17.txt");
  });
}

TEST(Graph, LoadMatrices_CheckCorrectSize) {
  using namespace s21;
  ASSERT_ANY_THROW({
    Graph g1;
    g1.loadGraphFromFile("../src/Tests/Matrices/18_fail_size.txt");
  });
}
TEST(Graph, LoadMatrices_CalcTypes1) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../src/Tests/Matrices/2_undir_unwei_positive.txt");
  ASSERT_TRUE(g1.getTypeByDirection() == TypeGraphByDirection::UNDIRECRED);
  ASSERT_TRUE(g1.getTypeByWeights() == TypeGraphByWeights::UNWEIGHTED);
  ASSERT_TRUE(g1.hasNegativeWeights() == false);
}
TEST(Graph, LoadMatrices_CalcTypes2) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../src/Tests/Matrices/2_undir_weight_pos.txt");
  ASSERT_TRUE(g1.getTypeByDirection() == TypeGraphByDirection::UNDIRECRED);
  ASSERT_TRUE(g1.getTypeByWeights() == TypeGraphByWeights::WEIGHTED);
  ASSERT_TRUE(g1.hasNegativeWeights() == false);
}
TEST(Graph, LoadMatrices_CalcTypes3) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../src/Tests/Matrices/2_dir_unweight_pos.txt");
  ASSERT_TRUE(g1.getTypeByDirection() == TypeGraphByDirection::DIRECTED);
  ASSERT_TRUE(g1.getTypeByWeights() == TypeGraphByWeights::UNWEIGHTED);
  ASSERT_TRUE(g1.hasNegativeWeights() == false);
}
TEST(Graph, LoadMatrices_CalcTypes4) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../src/Tests/Matrices/2_dir_weight_pos.txt");
  ASSERT_TRUE(g1.getTypeByDirection() == TypeGraphByDirection::DIRECTED);
  ASSERT_TRUE(g1.getTypeByWeights() == TypeGraphByWeights::WEIGHTED);
  ASSERT_TRUE(g1.hasNegativeWeights() == false);
}
TEST(Graph, LoadMatrices_CalcTypes5) {
  using namespace s21;
  Graph g1;
  g1.loadGraphFromFile("../src/Tests/Matrices/2_dir_weight_neg.txt");
  ASSERT_TRUE(g1.getTypeByDirection() == TypeGraphByDirection::DIRECTED);
  ASSERT_TRUE(g1.getTypeByWeights() == TypeGraphByWeights::WEIGHTED);
  ASSERT_TRUE(g1.hasNegativeWeights() == true);
}

TEST(Graph, LoadMatrices_CalcTypes6) {
  using namespace s21;
  Graph g1;
    try {
      g1.loadGraphFromFile("../src/Tests/Matrices/2_loop.txt");
  } catch (const std::exception& e) {
      std::cout << "ERROR";
  }
  std::cout<<"has negative weights"<<g1.hasLoop();
  ASSERT_TRUE(g1.hasLoop() == true);
}