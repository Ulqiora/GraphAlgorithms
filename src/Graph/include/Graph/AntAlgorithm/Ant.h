#pragma once
#include <map>
#include <memory>
#include <random>
#include <vector>

#include "../graph.h"
namespace s21 {

class Ant {
   private:
    std::vector<bool> passedCity;
    std::vector<int> path;
    int alpha = 1;
    int beta = 1;
    double pathLength = 0;
    int getRamdomValue(int minimum, int maximum);

   private:
    void initToStart(int sizeOfGraph);
    std::map<int, double>* createDictionaryOfAvailablePaths(Graph* graph);
    double calculateNumerator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap,
                              int currentIndex);
    double calcDenominator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap);
    std::map<int, double>* calcProbabilities(Graph* graph, const Matrix& pheromonesMap);

    void chooseWay(Graph* graph, std::map<int, double>* probabilities);

   public:
    Ant() = default;
    void findPath(Graph* graph, const Matrix& pheromonesMap);
    void updatePheromones(Matrix* pheromonesMap);
    double getPathLength() { return pathLength; }
    std::vector<int> getPath() { return path; }
};
}  // namespace s21