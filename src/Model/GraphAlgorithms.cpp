#include "GraphAlgorithms.h"
namespace s21 {

std::vector<int> GraphAlgorithm::depthFirstSearch(Graph &graph,
                                                  int startVertex) {
  stack<int> stackForAlgorithm;
  std::vector<bool> visitedVertex(graph.size(), false);
  std::vector<int> result(1, startVertex);
  visitedVertex[startVertex - 1] = true;
  int currenctIndex;
  do {
    currenctIndex = stackForAlgorithm.top();
    for (int i = 0; i < graph.size(); ++i) {
      if (!visitedVertex[i] && std::fabs(graph(i, currenctIndex)) >
                                   std::numeric_limits<double>::epsilon())
        stackForAlgorithm.push(i);
    }
    if (!stackForAlgorithm.empty()) {
      visitedVertex[stackForAlgorithm.top()] = true;
      result.push_back(stackForAlgorithm.top());
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

// Matrix GraphAlgorithm::getShortestPathsBetweenAllVertices(Graph &graph) {

// }

std::vector<int> GraphAlgorithm::getShortestPathBetweenVertices
                                                              (Graph &graph,
                                                              int vertex1,
                                                              int vertex2) {
  int result = 0;
  std::vector<int> vertices;
  fillVertices(vertices, graph.size(), vertex1);
}

void GraphAlgorithm::fillVertices(std::vector<int>& vert, int size, int vertex1) {
 for (int i = 0; i < size; i++) {
    if (i == vertex1) {
      vert.push_back(0);
    } else {
      vert.push_back(INFINITY);
    }
 }
}

int GraphAlgorithm::findMinVertex(std::vector<int>& vert) {
  int min = vert.data()[0];
  for (int i = 1; i < vert.size(); i++) {
    if (vert.data()[i] < min) {
      min = vert.data()[i];
    }
  }
    return min;
}

int GraphAlgorithm::findMinDestination(int minVertex, Matrix& matGraph) {
  int minDest = matGraph(minVertex, 0);
  int index = 0;
  for (int i = 1; i < matGraph.size(); i++) {
    if (matGraph(minVertex, i) < minDest) {
      minDest = matGraph(minVertex, i);
      index = i;
    }
  }
  return index;
}

void GraphAlgorithm::setVertex(Matrix& matGraph, std::vector<int>& vert, int minVert, int minDest) {
  if (vert.data()[minVert] > matGraph(minVert, minDest)) {
    vert.data()[minVert] += matGraph(minVert, minDest);
  }
}

}  // namespace s21