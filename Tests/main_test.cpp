#include <gtest/gtest.h>

#include "TravelingSalesmanProblem/test_NodeBnB.cpp"
#include "TravelingSalesmanProblem/test_matrixBnB.cpp"
#include "config.h"
#include "test_breadthAlgorithm.cpp"
#include "test_depthAlgorithm.cpp"
#include "test_getLeastSpanningTree.cpp"
#include "test_getShortestPathBetweenVertices.cpp"
#include "test_getShortestPathsBetweenAllVertices.cpp"
#include "test_loadGraph.cpp"
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
