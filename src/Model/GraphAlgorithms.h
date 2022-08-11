#pragma once
#include <algorithm>
#include <vector>
#include <limits>
#include <stack>

#include <queue>

//#include "SalesmanTask/TsmResult.h"
#include "StackAndQueue/queue.h"
#include "StackAndQueue/stack.h"
#include "graph.h"
namespace s21 {

class GraphAlgorithm {
 private:
  void addToQueue(Graph &graph, std::vector<bool> &visitedVertex,
                  queue<int> &queueForAlgorithm, int currentIndex);
  void addToResultForBreadth(queue<int> &queueForAlgorithm,
                             std::vector<int> &result);
  void addToStack(Graph &graph, std::vector<bool> &visitedVertex,
                  stack<int> &queueForAlgorithm, int currentIndex);
  void addToResultForDepth(stack<int> &queueForAlgorithm,
                           std::vector<int> &result);

 public:
  std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
  std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
  int getShortestPathBetweenVertices(Graph &graph, int vertex1,
                                                  int vertex2);
  // Matrix getShortestPathsBetweenAllVertices(Graph &graph);
  // Matrix getLeastSpanningTree(Graph &graph);
  // TsmResult solveTravelingSalesmanProblem(Graph &graph);

  private:
    std::stack<int> findIndexesOfVertice(std::vector<bool>& isVerticeUsed, Graph &graph, int begin);
    void fillIndexes(Graph &graph, std::vector<std::stack<int>>& indexes, int i);
    void setWeights(std::vector<bool>& isVerticeUsed, Graph& graph, std::vector<int>& weights, std::stack<int> indexes, int begin);
    void fillVertices(std::vector<int>& vert, int size, int vertex1);
    int findMinVertex(std::vector<int>& vert);
    int findMinDestination(int minVertex, Graph &graph);
    void setVertex(Graph &graph, std::vector<int>& vert, int minVert, int minDest);
};

}  // namespace s21