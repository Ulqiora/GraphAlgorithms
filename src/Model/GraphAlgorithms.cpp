#include "GraphAlgorithms.h"
namespace s21 {

std::vector<int> GraphAlgorithm::depthFirstSearch(Graph &graph,
                                                  int startVertex) {
  stack<int> stackForAlgorithm;
  std::vector<bool> visitedVertex(graph.size(), false);
  std::vector<int> result(1, startVertex);
  std::cout << "Size of result:" << result.size() << '\n';
  std::cout << "Value of first element of result:" << result.front() << '\n';
  visitedVertex[startVertex - 1] = true;
  int currenctIndex = startVertex - 1;
  do {
    for (int i = graph.size() - 1; i >= 0; --i) {
      std::cout << ((std::fabs(graph(i, currenctIndex)) >
                     std::numeric_limits<double>::epsilon()) &&
                    (!visitedVertex[i]))
                << std::endl;
      if ((!visitedVertex[i]) && (std::fabs(graph(i, currenctIndex)) >
                                  std::numeric_limits<double>::epsilon()))
        stackForAlgorithm.push(i);
    }
    if (!stackForAlgorithm.empty()) {
      visitedVertex[stackForAlgorithm.top()] = true;
      result.push_back(stackForAlgorithm.top() + 1);
      currenctIndex = stackForAlgorithm.top();
      stackForAlgorithm.pop();
    }
  } while (!stackForAlgorithm.empty());
  return result;
}

std::vector<int> GraphAlgorithm::breadthFirstSearch(Graph &graph,
                                                    int startVertex) {
  queue<int> queueForAlgorithm;
  std::vector<bool> visitedVertex(graph.size(), false);
  std::vector<int> result(1, startVertex);
  visitedVertex[startVertex - 1] = true;
  int currenctIndex;
  do {
    currenctIndex = queueForAlgorithm.top();
    for (int i = 0; i < graph.size(); ++i) {
      if (!visitedVertex[i] && std::fabs(graph(i, currenctIndex)) >
                                   std::numeric_limits<double>::epsilon())
        queueForAlgorithm.push(i);
    }
    if (!queueForAlgorithm.empty()) {
      visitedVertex[queueForAlgorithm.top()] = true;
      result.push_back(queueForAlgorithm.top());
      queueForAlgorithm.pop();
    }

  } while (!queueForAlgorithm.empty());
  return result;
}

// std::vector<int> GraphAlgorithm::getShortestPathBetweenVertices(Graph &graph,
//                                                                 int vertex1,
//                                                                 int vertex2)
//                                                                 {}

}  // namespace s21