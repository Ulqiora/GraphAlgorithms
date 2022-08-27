#include <gtest/gtest.h>

#include "../../Model/SalesmanTask/BnBAlgorithm/NodeBnB.h"

TEST(NodeBnB, NodeBnBCreateChildren) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5.txt");
    NodeBnB node(g1,0);
    node.createChildrens();
    ASSERT_TRUE(node(0).getLowerBound()==35);
    ASSERT_TRUE(node(1).getLowerBound()==53);
    ASSERT_TRUE(node(2).getLowerBound()==25);
    ASSERT_TRUE(node(3).getLowerBound()==31);
}