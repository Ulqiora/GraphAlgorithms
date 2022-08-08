#pragma once
#include <algorithm>
#include <vector>

//#include "SalesmanTask/TsmResult.h"
#include "StackAndQueue/queue.h"
#include "StackAndQueue/stack.h"
#include "graph.h"
namespace s21 {

class GraphAlgorithm {
 public:
  std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
  std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
  int getShortestPathBetweenVertices(Graph &graph, int vertex1,
                                                  int vertex2);
  // Matrix getShortestPathsBetweenAllVertices(Graph &graph);
  // Matrix getLeastSpanningTree(Graph &graph);
  // TsmResult solveTravelingSalesmanProblem(Graph &graph);

  private:
    void fillVertices(std::vector<int>& vert, int size, int vertex1);
    int findMinVertex(std::vector<int>& vert);
    int findMinDestination(int minVertex, Matrix& matGraph);
    void setVertex(Matrix& matGraph, std::vector<int>& vert, int minVert, int minDest);
};

}  // namespace s21