#include "Ant.h"
namespace s21{
    int Ant::getRamdomValue(int minimum,int maximum){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(minimum,maximum);
        return dist(rng);
    }

    void Ant::initToStart(int sizeOfGraph) {
        path.clear();
        passedCity.clear();
        passedCity.resize(sizeOfGraph, false);
        pathLength = 0;
        int random=getRamdomValue(0,sizeOfGraph-1);
        path.push_back(random);
        passedCity[random] = true;
    }

    std::map<int, double>* Ant::createDictionaryOfAvailablePaths(Graph* graph) {
        std::map<int, double>* result = new std::map<int, double>;
        for (int i = 0; i < graph->size(); ++i) {
            if ((std::fabs((*graph)(path.back(), i)) > std::numeric_limits<double>::epsilon()) &&
                (!passedCity[i]))
                result->insert(std::make_pair(i, (*graph)(path.back(), i)));
        }
        return result;
    }

    double Ant::calculateNumerator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap,
                              int currentIndex) {
        double eta = pow(1 / (*dictionaryOfAvailablePaths)[currentIndex], beta);
        double teta = pow(pheromonesMap(path.back(), currentIndex), alpha);
        return eta * teta;
    }

    double Ant::calcDenominator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap) {
        double sumOfAllProbabilities = 0.0;
        for (auto& i : (*dictionaryOfAvailablePaths)) {
            sumOfAllProbabilities +=
                pow(1 / i.second, beta) * pow(pheromonesMap(path.back(), i.first), alpha);
        }
        return sumOfAllProbabilities;
    }

    std::map<int, double>* Ant::calcProbabilities(Graph* graph, const Matrix& pheromonesMap) {
        std::map<int, double>* probabilities = new std::map<int, double>;
        std::map<int, double>* dictionaryOfAvailablePaths = createDictionaryOfAvailablePaths(graph);
        double numeratorProbability = 0.0;
        double denominatorProbability = calcDenominator(dictionaryOfAvailablePaths, pheromonesMap);
        for (auto& i : (*dictionaryOfAvailablePaths)) {
            numeratorProbability += calculateNumerator(dictionaryOfAvailablePaths, pheromonesMap, i.first);
            probabilities->insert(std::make_pair(i.first, numeratorProbability / denominatorProbability));
        }
        return probabilities;
    }

    void Ant::chooseWay(Graph* graph, std::map<int, double>* probabilities) {
        if (probabilities->size() == 1) {
            double temp=(*graph)(path.back(),(probabilities->begin()->first));
            path.push_back(probabilities->begin()->first);
            pathLength = pathLength + temp;
        } else {
            double randValue = getRamdomValue(1,100)/100.0;
            for (auto& it : (*probabilities)) {
                if (randValue <= it.second) {
                    pathLength += (*graph)(path.back(), it.first);
                    passedCity[it.first] = true;
                    path.push_back(it.first);
                    break;
                }
            }
        }
    }

    void Ant::findPath(Graph* graph, const Matrix& pheromonesMap) {
        int sizeGraph = graph->size();
        initToStart(sizeGraph);
        for (int i = 1; i < sizeGraph; ++i) {
            std::map<int, double>* probabilities = calcProbabilities(graph, pheromonesMap);
            chooseWay(graph, probabilities);
            delete probabilities;
        }
        pathLength += (*graph)(path.back(), path.front());
        path.push_back(path.front());
    }
    void Ant::updatePheromones(Matrix* pheromonesMap) {
        double lengthInverse = 1 / pathLength;
        int sizeMap = pheromonesMap->size();
        for (int i = 0; i < sizeMap; ++i) {
            (*pheromonesMap)(path[0], path[0 + 1]) += (lengthInverse);
        }
    }
}