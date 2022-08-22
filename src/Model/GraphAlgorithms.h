#pragma once
#include <algorithm>
#include <set>
#include <vector>
#include "SalesmanTask/AntAlgorithm/AntAlgorithm.h"
#include "SalesmanTask/BnBAlgorithm/BnBAlgorithm.h"
#include "StackAndQueue/queue.h"
#include "StackAndQueue/stack.h"
#include "graph.h"
namespace s21 {

int generateRandomValue(int minimum, int maximum) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(minimum, maximum);
    return dist(rng);
}

class GraphAlgorithms {
   private:
    void addToQueue(Graph &graph, std::vector<bool> &visitedVertex, queue<int> &queueForAlgorithm,
                    int currentIndex);
    void addToResultForBreadth(queue<int> &queueForAlgorithm, std::vector<int> &result);
    void addToStack(Graph &graph, std::vector<bool> &visitedVertex, stack<int> &queueForAlgorithm,
                    int currentIndex);
    void addToResultForDepth(stack<int> &queueForAlgorithm, std::vector<int> &result);
    bool isShortestPath(int way, int minWay) { return way != 0 && way < minWay; }

   public:
    std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
    std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
    double getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    Matrix getShortestPathsBetweenAllVertices(Graph &graph);
    Matrix getLeastSpanningTree(Graph &graph);
    TsmResult solveTravelingSalesmanProblem(Graph &graph);
    TsmResult solveTravelingSalesmanProblemBnB(Graph &graph);
    TsmResult solveTravelingSalesmanProblemBrudeForce(Graph &graph);
};

}  // namespace s21