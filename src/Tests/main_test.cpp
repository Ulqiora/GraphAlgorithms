#include <gtest/gtest.h>

#include "test_loadGraph.cpp"

#include "test_depthAlgorithm.cpp"
#include "test_breadthAlgorithm.cpp"
#include "test_getLeastSpanningTree.cpp"
#include "test_getShortestPathsBetweenAllVertices.cpp"
#include "test_getShortestPathBetweenVertices.cpp"
#include "test_getShortestPathBetweenVertices.cpp"
#include "TravelingSalesmanProblem/test_NodeBnB.cpp"
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
