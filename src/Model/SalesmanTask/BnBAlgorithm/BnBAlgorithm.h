#pragma once
#include "../../graph.h"
#include "../TsmResult.h"
#include "NodeBnB.h"
namespace s21 {

class BnBAlgorithm {
   private:
    Graph* graph=nullptr;
    NodeBnB head;
    std::vector<NodeBnB*> currentNodes;
   private:
    void createTree();
    void createTreeForRoot();
    TsmResult createTsmResult();
    void deepeningByOneLevel();
   public:
   BnBAlgorithm():currentNodes(0){}
    TsmResult start(Graph& example,int startIndex);
};

}  // namespace s21