#include <gtest/gtest.h>

#include "../../Model/SalesmanTask/BnBAlgorithm/MatrixBnB.h"

TEST(MatrixBnB, CreateMatrixByGraph) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5.txt");
    MatrixBnB res(g1);
    for(int i=0;i<g1.size();++i){
        for(int j=0;j<g1.size();++j){
            ASSERT_TRUE(res(i,j).first.row==i);
            ASSERT_TRUE(res(i,j).first.col==j);
            // std::cout<<"ku "<<i<<' '<<j<<'\n';
            if(i!=j)
                ASSERT_NEAR(res(i,j).second,g1(i,j),std::numeric_limits<double>::epsilon());
            else 
                ASSERT_TRUE(res(i,j).second == numLimD::infinity());
        }
    }
}

TEST(MatrixBnB, findMinimum) {
    using namespace s21;
    Graph g1;
    g1.loadGraphFromFile("../materials/matrices/5.txt");
    MatrixBnB res(g1);
    std::vector<double> *out=res.findMinimumInAllRow();
}