#pragma once
#include <algorithm>
#include <vector>

//#include "SalesmanTask/TsmResult.h"
#include "SalesmanTask/ant algorithm/AntAlgorithm.h"
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
  // std::vector<int> getShortestPathBetweenVertices(Graph &graph, int vertex1,
  //                                                 int vertex2);
  // Matrix getShortestPathsBetweenAllVertices(Graph &graph);
  // Matrix getLeastSpanningTree(Graph &graph);
  TsmResult solveTravelingSalesmanProblem(Graph &graph);
};

}  // namespace s21