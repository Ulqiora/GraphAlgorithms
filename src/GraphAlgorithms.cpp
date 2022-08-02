#include "GraphAlgorithms.h"
namespace s21{

std::vector<int> GraphAlgorithm::depthFirstSearch(Graph& graph, int startVertex) {
    stack<int> stackForAlgorithm;
    std::vector<bool> visitedVertex(graph.size(),false);
    std::vector<int> result(1,startVertex);
    visitedVertex[startVertex-1]=true;
    int currenctIndex;
    do {
        currenctIndex=stackForAlgorithm.top();
        for (int i = 0; i < graph.size(); ++i) {
            if (!visitedVertex[i]&&graph(i,currenctIndex))
                stackForAlgorithm.push(i);
        }
        if(!stackForAlgorithm.empty()) {
            visitedVertex[stackForAlgorithm.top()]=true;
            result.push_back(stackForAlgorithm.top());
            stackForAlgorithm.pop();
        }
    } while (!stackForAlgorithm.empty());
    return result;
}


std::vector<int> GraphAlgorithm::breadthFirstSearch(Graph &graph, int startVertex)
{
    queue<int> queueForAlgorithm;
    std::vector<bool> visitedVertex(graph.size(),false);
    std::vector<int> result(1,startVertex);
    visitedVertex[startVertex-1]=true;
    int currenctIndex;
    do {
        currenctIndex=queueForAlgorithm.top();
        for (int i = 0; i < graph.size(); ++i) {
            if (!visitedVertex[i]&&graph(i,currenctIndex))
                queueForAlgorithm.push(i);
        }
        if(!queueForAlgorithm.empty()) {
            visitedVertex[queueForAlgorithm.top()]=true;
            result.push_back(queueForAlgorithm.top());
            queueForAlgorithm.pop();
        }
    } while (!queueForAlgorithm.empty());
    return result;
}


}