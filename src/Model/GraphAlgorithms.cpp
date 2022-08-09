#include "GraphAlgorithms.h"
namespace s21 {

std::vector<int> GraphAlgorithm::depthFirstSearch(Graph &graph,
                                                  int startVertex) {
  int currentIndex = startVertex - 1;
  stack<int> stackForAlgorithm;
  std::vector<bool> visitedVertex(graph.size(), false);
  std::vector<int> result(1, startVertex);
  visitedVertex[startVertex - 1] = true;
  stackForAlgorithm.push(currentIndex);
  while (!stackForAlgorithm.empty()) {
    currentIndex = stackForAlgorithm.top();
    stackForAlgorithm.pop();
    addToStack(graph, visitedVertex, stackForAlgorithm, currentIndex);
    addToResultForDepth(stackForAlgorithm, result);
  }
  return result;
}

void GraphAlgorithm::addToStack(Graph &graph, std::vector<bool> &visitedVertex,
                                stack<int> &stackForAlgorithm,
                                int currentIndex) {
  for (int i = graph.size() - 1; i >= 0; --i) {
    if ((!visitedVertex[i]) && (std::fabs(graph(i, currentIndex)) >
                                std::numeric_limits<double>::epsilon())) {
      stackForAlgorithm.push(i);
      visitedVertex[i] = true;
    }
  }
}

void GraphAlgorithm::addToResultForDepth(stack<int> &stackForAlgorithm,
                                         std::vector<int> &result) {
  if (!stackForAlgorithm.empty()) result.push_back(stackForAlgorithm.top() + 1);
}

std::vector<int> GraphAlgorithm::breadthFirstSearch(Graph &graph,
                                                    int startVertex) {
  int currentIndex = startVertex - 1;
  queue<int> queueForAlgorithm;
  std::vector<bool> visitedVertex(graph.size(), false);
  std::vector<int> result(0);
  result.push_back(startVertex);
  visitedVertex[currentIndex] = true;
  queueForAlgorithm.push(currentIndex);
  while (!queueForAlgorithm.empty()) {
    currentIndex = queueForAlgorithm.top();
    queueForAlgorithm.pop();
    std::cout << "current index:" << currentIndex << std::endl;
    addToQueue(graph, visitedVertex, queueForAlgorithm, currentIndex);
    addToResultForBreadth(queueForAlgorithm, result);
  }
  return result;
}

void GraphAlgorithm::addToQueue(Graph &graph, std::vector<bool> &visitedVertex,
                                queue<int> &queueForAlgorithm,
                                int currentIndex) {
  for (int i = 0; i < graph.size(); ++i) {
    if ((!visitedVertex[i]) && std::fabs(graph(currentIndex, i)) >
                                   std::numeric_limits<double>::epsilon()) {
      queueForAlgorithm.push(i);
      visitedVertex[i] = true;
      std::cout << i << '\n';
    }
  }
}

void GraphAlgorithm::addToResultForBreadth(queue<int> &queueForAlgorithm,
                                           std::vector<int> &result) {
  if (!queueForAlgorithm.empty()) result.push_back(queueForAlgorithm.top() + 1);
  std::cout << "current return: ";
  for (auto &i : result) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

}  // namespace s21