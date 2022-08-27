#include <gtest/gtest.h>

#include <string>

#include "../Model/GraphAlgorithms.h"

// TEST(GraphAlgorithms, getShortestPathBetweenVertices) {
//     using namespace s21;
//     Graph g1;
//     g1.loadGraphFromFile("../materials/matrices/5.txt");
//     GraphAlgorithms ga;
//     s21::Matrix result = ga.getShortestPathBetweenVertices(g1);
//     MatrixBnB result2{{0, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 0, 0, 0, 1}, {1, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
//     for(int i=0;i<g1.size();i++){
//         for(int j=0;j<g1.size();j++){
//             ASSERT_TRUE(result(i,j) == result2(i,j));
//         }
//     }
// }

TEST(GraphAlgorithms, getShortestPathBetweenVertices) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5_BNB.txt");
    GraphAlgorithms ga;
    double value = ga.getShortestPathBetweenVertices(g1,1,2);
    ASSERT_TRUE(value == 15);
}

TEST(GraphAlgorithms, getShortestPathBetweenVertices1) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5_BNB.txt");
    GraphAlgorithms ga;
    double value = ga.getShortestPathBetweenVertices(g1,1,2);
    ASSERT_TRUE(value == 15);
}