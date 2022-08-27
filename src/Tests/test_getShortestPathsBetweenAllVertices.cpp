#include <gtest/gtest.h>

#include <string>

#include "../Model/GraphAlgorithms.h"

TEST(GraphAlgorithms, getShortestPathsBetweenAllVertices) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5.txt");
    GraphAlgorithms ga;
    s21::Matrix result = ga.getShortestPathsBetweenAllVertices(g1);
    MatrixBnB result2{{0,1,1,1,2}, {1,0,1,2,2}, {1,1,0,2,1}, {1,2,2,0,3}, {2,2,1,3,0}};
    for(int i=0;i<g1.size();i++){
        for(int j=0;j<g1.size();j++){
            ASSERT_TRUE(result(i,j) == result2(i,j));
        }
    }
}
