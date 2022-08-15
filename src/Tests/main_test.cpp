#include <gtest/gtest.h>

#include "test_loadGraph.cpp"

#include "test_depthAlgorithm.cpp"
#include "test_breadthAlgorithm.cpp"
#include "BnBAlgorithmTests/test_matrixBnB.cpp"
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
