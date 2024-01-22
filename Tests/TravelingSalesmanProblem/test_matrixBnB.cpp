#include <Graph/GraphAlgorithms.h>
#include <gtest/gtest.h>

#include "config.h"
TEST(MatrixBnB, CreateMatrixByGraph) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile = pathFile / "materials" / "matrices" / "5.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::MatrixBnB res(g1);
    for (int i = 0; i < g1.size(); ++i) {
        for (int j = 0; j < g1.size(); ++j) {
            if (i != j)
                ASSERT_NEAR(res(i, j), g1(i, j), std::numeric_limits<double>::epsilon());
            else
                ASSERT_TRUE(res(i, j) == s21::numLimD::infinity());
        }
    }
}

TEST(MatrixBnB, findMinimum) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile = pathFile / "materials" / "matrices" / "5_BNB.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::MatrixBnB res(g1);
    std::vector<double> *out = res.findMinimumInAllRows();
    std::vector<double> minimums{10, 2, 2, 3, 4};
    for (int i = 0; i < g1.size(); ++i) {
        ASSERT_NEAR(minimums[i], (*out)[i], std::numeric_limits<double>::epsilon());
    }
}