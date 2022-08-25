#include "GraphAlgorithms.h"
namespace s21 {

int generateRandomValue(int minimum, int maximum) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(minimum, maximum);
    return dist(rng);
}

std::vector<int> GraphAlgorithms::depthFirstSearch(Graph &graph, int startVertex) {
    if (graph.hasLoop()) throw std::invalid_argument("This graph have loop!");
    if (startVertex < 1 || startVertex > graph.size())
        throw std::invalid_argument("Wrong starting point value");
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

void GraphAlgorithms::addToStack(Graph &graph, std::vector<bool> &visitedVertex,
                                 stack<int> &stackForAlgorithm, int currentIndex) {
    for (int i = graph.size()-1; i >= 0; --i) {
        if ((!visitedVertex[i]) &&
            (std::fabs(graph(currentIndex, i)) > std::numeric_limits<double>::epsilon())) {
            stackForAlgorithm.push(i);
            visitedVertex[i] = true;
        }
    }
}

void GraphAlgorithms::addToResultForDepth(stack<int> &stackForAlgorithm, std::vector<int> &result) {
    if (!stackForAlgorithm.empty()) result.push_back(stackForAlgorithm.top() + 1);
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {
    if (graph.hasLoop()) throw std::invalid_argument("This graph have loop!");
    if (startVertex < 1 || startVertex > graph.size())
        throw std::invalid_argument("Wrong starting point value");
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
        addToQueue(graph, visitedVertex, queueForAlgorithm, currentIndex);
        addToResultForBreadth(queueForAlgorithm, result);
    }
    return result;
}

void GraphAlgorithms::addToQueue(Graph &graph, std::vector<bool> &visitedVertex,
                                 queue<int> &queueForAlgorithm, int currentIndex) {
    for (int i = 0; i < graph.size(); ++i) {
        if ((!visitedVertex[i]) &&
            std::fabs(graph(currentIndex, i)) > std::numeric_limits<double>::epsilon()) {
            queueForAlgorithm.push(i);
            visitedVertex[i] = true;
        }
    }
}

void GraphAlgorithms::addToResultForBreadth(queue<int> &queueForAlgorithm, std::vector<int> &result) {
    if (!queueForAlgorithm.empty()) result.push_back(queueForAlgorithm.top() + 1);
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(Graph &graph) {
    if (!graph.isCompliteGraph()) throw std::invalid_argument("This graph is not complete!");
    if (graph.hasNegativeWeights()) throw std::invalid_argument("This graph has negative weights!");
    if (graph.size() < 2) throw std::invalid_argument("This graph is very small! Try again!");
    AntAlgorithm aa;
    return aa.start(&graph);
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblemBnB(Graph &graph) {
    if (!graph.isCompliteGraph()) throw std::invalid_argument("This graph is not complete!");
    if (graph.hasNegativeWeights()) throw std::invalid_argument("This graph has negative weights!");
    if (graph.size() < 2) throw std::invalid_argument("This graph is very small! Try again!");
    BnBAlgorithm bb;
    return bb.start(graph, 1);
}

Matrix GraphAlgorithms::getLeastSpanningTree(Graph &graph) {
    if (graph.getTypeByDirection() == TypeGraphByDirection::DIRECTED) {
        throw std::invalid_argument("This graph is directed!");
    }
    if (graph.hasLoop()) throw std::invalid_argument("This graph рфы loops!");
    Matrix matrix(std::move(graph.getMatrix()));
    size_t size = graph.size();
    std::set<int> visitedVertices;
    std::vector<std::pair<int, int>> traveledEdges;
    visitedVertices.insert(generateRandomValue(0, size - 1));
    while (visitedVertices.size() < size) {
        int minWeight = std::numeric_limits<int>::infinity(), to = 0, from = 0;
        for (auto i : visitedVertices) {
            for (size_t j = 0; j < size; j++) {
                if (isShortestPath(matrix(j, i), minWeight) && !visitedVertices.count(j)) {
                    minWeight = matrix(j, i);
                    from = i;
                    to = j;
                }
            }
        }
        traveledEdges.push_back({from, to});
        visitedVertices.insert(to);
    }
    Matrix result(size);
    for (auto &i : traveledEdges)
        result(i.first, i.second) = result(i.second, i.first) = matrix(i.first, i.second);
    return result;
}

Matrix GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &graph) {
    Matrix matrix = graph.getMatrix();
    int size = graph.size();
    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) {
                if (matrix(i, k) && matrix(k, j) && i != j)
                    if (matrix(i, k) + matrix(k, j) < matrix(i, j) || matrix(i, j) == 0)
                        matrix(i, j) = matrix(i, k) + matrix(k, j);
            }
    return matrix;
}

double GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
    vertex1 -= 1;
    vertex2 -= 1;
    if (vertex1 < 0 || vertex2 < 0) {
        throw std::invalid_argument("Invalide index");
    }
    s21::queue<int> myQueue;
    std::vector<bool> used(graph.size(), false);
    std::vector<double> minRoad(graph.size(), std::numeric_limits<double>::infinity());
    Matrix matrixGraph = graph.getMatrix();
    minRoad[vertex1] = 0;
    myQueue.push(vertex1);
    while (!myQueue.empty()) {
        int value = myQueue.front();
        myQueue.pop();
        if (used[value] == true) {
            continue;
        }
        used[value] = true;
        for (int i = 0; i < graph.size(); i++) {
            double tempRoad = minRoad[value] + matrixGraph(value, i);
            if (matrixGraph(value, i) != 0 && used[i] == false && minRoad[i] > tempRoad) {
                minRoad[i] = tempRoad;
                if (i != vertex2) {
                    myQueue.push(i);
                }
            }
        }
    }
    return minRoad[vertex2];
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblemBrudeForce(Graph &graph) {
    if (!graph.isCompliteGraph()) throw std::invalid_argument("This graph is not complete!");
    if (graph.hasNegativeWeights()) throw std::invalid_argument("This graph has negative weights!");
    if (graph.size() < 2) throw std::invalid_argument("This graph is very small! Try again!");
    TsmResult result;
    result.distance = INFINITY;
    std::vector<int> vertices;
    for (int i = 1; i < graph.size(); i++) vertices.push_back(i);
    do {
        double curPathWeight = 0;
        int from = 0;
        for (size_t i = 0; i < vertices.size(); i++) {
            int to = vertices[i];
            curPathWeight += graph.getMatrix()(from, to);
            from = to;
        }
        curPathWeight += graph.getMatrix()(from, 0);
        if (result.distance > curPathWeight) {
            result.distance = curPathWeight;
            result.vertices = vertices;
        }
    } while (next_permutation(vertices.begin(), vertices.end()));
    result.vertices.push_back(result.vertices[0]);
    return result;
}

}  // namespace s21