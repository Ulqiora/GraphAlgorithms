#pragma once
#include "../../graph.h"
#include "../TsmResult.h"
#include "NodeBnB.h"
namespace s21 {

class BnBAlgorithm {
   private:
    Graph* graph=nullptr;
    NodeBnB head;
    NodeBnB* currentNode;
   private:
    void createTree(){
        currentNode->createChildrens();
        if(currentNode->sizeChildrens()==0) return;
        auto& min = currentNode->frontChildren();
        for(auto& node: (*currentNode)){
            if(min.getLowerBound()>node.getLowerBound()) min = std::move(node);
        }
        currentNode=& min;
        createTree();
    }
    TsmResult createTsmResult(){
        TsmResult result;
        result.vertices=currentNode->path();
        result.vertices.push_back(result.vertices.front());
        result.distance=currentNode->getLowerBound();
        for(auto& i :result.vertices) i++;
        return result;
    }
   public:
    TsmResult start(Graph& example,int startIndex){
        graph=&example;
        head=NodeBnB(example,startIndex-1);
        currentNode=&head;
        createTree();
        return createTsmResult();
    }
};

}  // namespace s21