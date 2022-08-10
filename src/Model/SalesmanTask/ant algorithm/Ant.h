#pragma once
#include <map>
#include <memory>
#include <random>
#include <vector>

#include "../../graph.h"
namespace s21 {

class Ant {
   private:
    std::vector<bool> passedСity;
    std::vector<int> path;
    const int proximityRatio = 1;
    const int alpha = 1;
    const int beta = 1;
    const int evaporationCoef = 0.2;
    double pathLength = 0;
    // fixed seed
    const int seed = 123;
    // Mersenne Twister random engine:
    std::mt19937 urbg{seed};
    std::uniform_int_distribution<int> dist{0, 100};

   private:
    void updatePheromones() {}
    void initToStart(int sizeOfGraph) {
        passedСity.resize(sizeOfGraph, false);
        pathLength = 0;
        path.push_back(0);
        passedСity[0] = true;
    }
    
    std::map<int, double>* createDictionaryOfAvailablePaths(Graph* graph){
      std::map<int, double>* result= new std::map<int, double>;
      for(int i=0;i<graph->size();++i){
        if((std::fabs((*graph)(path.back(),i))>std::numeric_limits<double>::epsilon())&&
            (!passedСity[i]))
          result->insert(std::make_pair(i,(*graph)(path.back(),i)));
      }
      return result;
    }

    double calculateNumerator(std::map<int, double>* dictionaryOfAvailablePaths,
                                const Matrix& pheromonesMap, int currentIndex) {
        double eta = pow(1 / (*dictionaryOfAvailablePaths)[currentIndex], beta);
        double teta = pow(pheromonesMap(path.back(), currentIndex), alpha);
        return eta * teta;
    }

    double calcDenominator(std::map<int, double>* dictionaryOfAvailablePaths,
                                const Matrix& pheromonesMap){
        double sumOfAllProbabilities = 0.0;
        for (auto& i:(*dictionaryOfAvailablePaths)) {
            sumOfAllProbabilities +=
                pow(1 / i.second, beta) * pow(pheromonesMap(path.back(), i->first), alpha);
        }
        return sumOfAllProbabilities;
    }

    std::shared_ptr<std::map<int, double>> calcProbabilities(Graph* graph, const Matrix& pheromonesMap) {
        std::map<int, double>* probabilities = new std::map<int, double>;
        std::map<int, double>* dictionaryOfAvailablePaths = createDictionaryOfAvailablePaths(graph);
        double numeratorProbability = 0.0;
        double denominatorProbability = calcDenominator(dictionaryOfAvailablePaths, pheromonesMap);
        for (auto& i:(*dictionaryOfAvailablePaths)) {
            numeratorProbability +=
                calculateNumerator(dictionaryOfAvailablePaths, pheromonesMap,i.first);
            probabilities->insert(std::make_pair(i.first, numeratorProbability/denominatorProbability));
        }
        return std::make_shared<std::map<int, double>>(probabilities);
    }

    void chooseWay(Graph* graph, std::shared_ptr<std::map<int, double>> probabilities) {
        if (probabilities->size() == 1) {
            path.push_back(probabilities->begin()->first);
        } else {
            double randValue = dist(urbg);
            for (auto& it : (*probabilities)) {
                if (randValue <= it.second) {
                    pathLength += (*graph)(path.back(), it.first);
                    passedСity[it.first] = true;
                    path.push_back(it.first);
                    break;
                }
            }
            pathLength += (*graph)(path.front(), path.back());
            path.push_back(path.front());
        }
    }

   public:
    Ant() = default;
    void findPath(Graph* graph, const Matrix& pheromonesMap) {
        initToStart(graph->size());
        for (int i = 1; i < graph->size(); ++i) {
            std::shared_ptr<std::map<int, double>> probabilities = calcProbabilities(graph, pheromonesMap);
            chooseWay(graph, probabilities);
        }
    }
};
}  // namespace s21