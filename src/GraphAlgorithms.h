#include <algorithm>
#include <vector>

#include "SalesmanTask/TsmResult.h"
#include "StackAndQueue/queue.h"
#include "StackAndQueue/stack.h"
#include "graph.h"
namespace s21 {

class GraphAlgorithm {
 public:
  std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
  std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
  std::vector<int> getShortestPathBetweenVertices(Graph &graph, int vertex1,
                                                  int vertex2);
  Matrix getShortestPathsBetweenAllVertices(Graph &graph);
  Matrix getLeastSpanningTree(Graph &graph);
  TsmResult solveTravelingSalesmanProblem(Graph &graph);
};

}  // namespace s21