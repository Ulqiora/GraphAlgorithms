#include "graph.h"
#include "StackAndQueue/queue.h"
#include "StackAndQueue/stack.h"
#include <algorithm>
#include <vector>
namespace s21{

class GraphAlgorithm{
public:
    struct TsmResult {
        int* vertices;    // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
        double distance;  // длина этого маршрута
    };
    std::vector<int> depthFirstSearch(Graph& graph, int startVertex);
    std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
    std::vector<int> getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    Matrix getShortestPathsBetweenAllVertices(Graph &graph);
    Matrix getLeastSpanningTree(Graph &graph);
    TsmResult solveTravelingSalesmanProblem(Graph &graph);
    
};

}