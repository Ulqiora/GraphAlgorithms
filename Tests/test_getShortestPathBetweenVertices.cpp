#include <gtest/gtest.h>

#include <string>

#include "../src/Model/include/GraphAlgorithms.h"

// TEST(GraphAlgorithmsTest, getShortestPathBetweenVertices) {
//   s21::Graph g1;
//   g1.loadGraphFromFile("../materials/matrices/5.txt");
//   s21::GraphAlgorithms ga;
//   s21::Matrix result = ga.getShortestPathBetweenVertices(g1);
//   s21::MatrixBnB result2{{0, 1, 1, 1, 0},
//                          {1, 0, 0, 0, 0},
//                          {1, 0, 0, 0, 1},
//                          {1, 0, 0, 0, 0},
//                          {0, 0, 1, 0, 0}};
//   for (int i = 0; i < g1.size(); i++) {
//     for (int j = 0; j < g1.size(); j++) {
//       ASSERT_TRUE(result(i, j) == result2(i, j));
//     }
//   }
// }

TEST(GraphAlgorithmsTest, getShortestPathBetweenVertices_test) {
    s21::Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5_BNB.txt");
    s21::GraphAlgorithms ga;
    double value = ga.getShortestPathBetweenVertices(g1, 1, 2);
    ASSERT_EQ(value, 15);
}

TEST(GraphAlgorithmsTest, getShortestPathBetweenVertices_test1) {
    s21::Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5_BNB.txt");
    s21::GraphAlgorithms ga;
    double value = ga.getShortestPathBetweenVertices(g1, 1, 2);
    ASSERT_EQ(value, 15);
}
