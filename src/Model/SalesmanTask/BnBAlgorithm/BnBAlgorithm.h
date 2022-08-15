#pragma once
#include "../../graph.h"
#include "../TsmResult.h"
#include "Index.h"
#include "Node.h"
namespace s21 {

class BnBAlgorithm {
   private:
    Graph* graph=nullptr;
    Node head;
   private:
    void initToStart(Graph& example){
        graph=&example;
        MatrixBnB temp=matrixBnB::createMatrixBnB(example);
        
    }
   public:
    TsmResult start(Graph& example){
        initToStart(example);
        
    }
};

}  // namespace s21