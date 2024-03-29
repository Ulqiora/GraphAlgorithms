#include <Graph/GraphAlgorithms.h>
#include <gtest/gtest.h>

#include <string>

TEST(GraphAlgorithms, leastSpanningTree) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile = pathFile / "materials" / "matrices" / "5.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    s21::Matrix result = ga.getLeastSpanningTree(g1);
    s21::MatrixBnB result2{
            {0, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 1, 0, 0}};
    for (int i = 0; i < g1.size(); i++) {
        for (int j = 0; j < g1.size(); j++) {
            ASSERT_TRUE(result(i, j) == result2(i, j));
        }
    }
}

TEST(GraphAlgorithms, leastSpanningTree_Direction) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile = pathFile / "materials" / "matrices" / "5_BNB.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    ASSERT_ANY_THROW(s21::Matrix result = ga.getLeastSpanningTree(g1););
}
