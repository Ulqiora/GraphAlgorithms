#include <gtest/gtest.h>

#include <string>
#include <filesystem>
#include <Graph/GraphAlgorithms.h>
#include "config.h"
TEST(GraphAlgorithms, BFT) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"4.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.breadthFirstSearch(g1, 1);
    std::vector<int> result2;
    result2.push_back(1);
    result2.push_back(2);
    result2.push_back(3);
    result2.push_back(4);
    ASSERT_TRUE(result == result2);
}

TEST(GraphAlgorithms, BFT2) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"5.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.breadthFirstSearch(g1, 1);
    std::vector<int> result2;
    result2.push_back(1);
    result2.push_back(2);
    result2.push_back(3);
    result2.push_back(4);
    result2.push_back(5);
    ASSERT_TRUE(result == result2);
}

TEST(GraphAlgorithms, BFT3) {
    s21::Graph g1;
    std::filesystem::path pathFile(PROJECT_PATH);
    pathFile=pathFile/"materials"/"matrices"/"18.txt";
    g1.loadGraphFromFile(pathFile.string());
    s21::GraphAlgorithms ga;
    std::vector<int> result = ga.breadthFirstSearch(g1, 1);
    std::vector<int> result2{1, 2, 3, 10, 5, 6, 7, 15, 16, 9, 11, 12, 14, 17, 18};
    ASSERT_TRUE(result == result2);
}
