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
  // int currentIndex = startVertex - 1;
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
    int begin = vertex1 - 1;
    std::vector<int> weights;
    try {
      fillVertices(weights, graph.size(), begin);
      // for (auto& k: weights) {
      //   std::cout << k << ' ';
      // }
      while (weights[vertex2 - 1] >= std::numeric_limits<int>::max()) {
        std::stack<int> indexes = findIndexesOfVertice(graph, begin);
        int nextIndex = indexes.top();
        setWeights(graph, weights, indexes, begin);
        begin = nextIndex;
        std::cout << "begin = " << begin << std::endl;
      }
    } catch (std::exception& e) {
      throw;
    }
    return weights[vertex2 - 1];
}

std::stack<int> GraphAlgorithm::findIndexesOfVertice(Graph &graph, int begin) {
  std::stack<int> result;
  std::vector<int> pieceOfGraph;
  for (int k = 0; k < graph.size(); k++) {
    pieceOfGraph.push_back(graph(begin, k));
  }
  while(true) {
    int maxValue = 0;
    int maxIndex;
    for (int i = 0; i < graph.size(); i++) {
      if (pieceOfGraph[i] > maxValue) {
        maxValue = pieceOfGraph[i];
        maxIndex = i;
      }
    }
    if (maxValue > 0) {
      result.push(maxIndex);
      pieceOfGraph[maxIndex] = -1;
    } else {
      break;
    }
  }
  if (result.empty()) {
    throw::std::out_of_range("empty stack");
  }
  // while (!result.empty()) {
  //   int x = result.top();
  //   std::cout << x << ' ';
  //   result.pop();
  // }
  // std::cout << "\n--------------";
  return result;
}

void GraphAlgorithm::setWeights(Graph& graph, std::vector<int>& weights, std::stack<int> indexes, int begin) {
  for (unsigned int i = 0; i < indexes.size(); i++) {
    if (weights[indexes.top()] > graph(begin, indexes.top())) {
      weights[indexes.top()] = weights[begin] + graph(begin, indexes.top());
    }
    indexes.pop();
  }
    weights[begin] = -1;
}

// int GraphAlgorithm::getShortestPathBetweenVertices
//                                                               (Graph &graph,
//                                                               int vertex1,
//                                                               int vertex2) {
//   std::vector<int> vertices;
//   fillVertices(vertices, graph.size(), vertex1);
//   // while (vertices.data()[vertex2] == std::numeric_limits<int>::infinity()) {
//   for (int i = 0; i < graph.size(); i++) {
//     int minVert = findMinVertex(vertices);
//     int minDest = findMinDestination(minVert, graph);
//     setVertex(graph, vertices, minVert, minDest);
//   }
//   return vertices.data()[vertex2];
// }

void GraphAlgorithm::fillVertices(std::vector<int>& vert, int size, int vertex1) {
 for (int i = 0; i < size; i++) {
    if (i == vertex1) {
      vert.push_back(0);
    } else {
      vert.push_back(std::numeric_limits<int>::max());
    }
 }
}

// int GraphAlgorithm::findMinVertex(std::vector<int>& vert) {
//     int min;
//     int index;
//   for (unsigned int k = 0; k < vert.size(); k++) {
//     if (vert.data()[k] != -1) {
//       index = k;
//       min = vert.data()[k];
//       break;
//     }
//   }
//   for (unsigned int i = 1; i < vert.size(); i++) {
//     if (vert.data()[i] != -1 && vert.data()[i] < min) {
//       index = i;
//       min = vert.data()[i];
//     }
//   }
//     return index;
// }

// int GraphAlgorithm::findMinDestination(int minVertex, Graph &graph) {
//   int minDest;
//   int index;
//   for (int k = 0; k < graph.size(); k++) {
//     if (graph(minVertex, k) > 0) {
//       index = k;
//       minDest = graph(minVertex, k);
//       break;
//     }
//   }
//   for (int i = 1; i < graph.size(); i++) {
//     if (graph(minVertex, i) > 0 && graph(minVertex, i) < minDest) {
//       minDest = graph(minVertex, i);
//       index = i;
//     }
//   }
//   return index;
// }

// void GraphAlgorithm::setVertex(Graph &graph, std::vector<int>& vert, int minVert, int minDest) {
//   if (vert.data()[minDest] > graph(minVert, minDest)) {
//     vert.data()[minDest] = graph(minVert, minDest);
//     vert.data()[minVert] = -1;
//   }
// }

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