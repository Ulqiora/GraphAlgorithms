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

int GraphAlgorithm::getShortestPathBetweenVertices
                                                              (Graph &graph,
                                                              int vertex1,
                                                              int vertex2) {
  std::vector<int> vertices;
  fillVertices(vertices, graph.size(), vertex1);
  while (vertices.data()[vertex2] == INFINITY) {
    int minVert = findMinVertex(vertices);
    int minDest = findMinDestination(minVert, graph.getMatrix());
    setVertex(graph.getMatrix(), vertices, minVert, minDest);
  }
  return vertices.data()[vertex2];
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
    int min;
  for (int k = 0; k < vert.size(); k++) {
    if (vert.data()[k] != -1) {
      min = vert.data()[k];
      break;
    }
  }
  for (int i = 1; i < vert.size(); i++) {
    if (vert.data()[i] != -1 && vert.data()[i] < min) {
      min = vert.data()[i];
    }
  }
    return min;
}

int GraphAlgorithm::findMinDestination(int minVertex, Matrix& matGraph) {
  int minDest;
  for (int k = 0; k < matGraph.size(); k++) {
    if (matGraph(minVertex, k) > 0) {
      minDest = matGraph(minVertex, 0);
      break;
    }
  }
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
  if (vert.data()[minDest] > matGraph(minVert, minDest)) {
    vert.data()[minDest] = matGraph(minVert, minDest);
    vert.data()[minVert] = -1;
  }
}

}  // namespace s21

// int main() {
//   using namespace s21;
//   Graph myG;
//   myG.loadGraphFromFile("/Users/cojess/GraphAlgorithms/materials/matrices/1.txt");
//   GraphAlgorithm algo;
//   int res = algo.getShortestPathBetweenVertices(myG, 0, 17);
//   std::cout << "res = " << res << std::endl;
//   return 0;
// }