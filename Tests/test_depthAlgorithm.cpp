#include <gtest/gtest.h>

#include <string>
#include <Graph/GraphAlgorithms.h>
#include <filesystem>
TEST(GraphAlgorithms, DFT) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"4.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.depthFirstSearch(g1, 1);
    std::vector<int> result2{1, 2, 4, 3};
    ASSERT_TRUE(result == result2);
}

TEST(GraphAlgorithms, DFT2) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"5.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.depthFirstSearch(g1, 1);
    std::vector<int> result2{1, 2, 3, 5, 4};
    ASSERT_TRUE(result == result2);
}
TEST(GraphAlgorithms, DFT3) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"18.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.depthFirstSearch(g1, 1);
    std::vector<int> result2{1, 2, 5, 9, 14, 3, 6, 11, 7, 12, 17, 18, 10, 15, 16};
}
