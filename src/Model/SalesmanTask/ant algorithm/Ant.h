#pragma once
#include <map>
#include <memory>
#include <random>
#include <vector>

#include "../../graph.h"
namespace s21 {

class Ant {
   private:
    std::vector<bool> passedCity;
    std::vector<int> path;
    int proximityRatio = 1;
    int alpha = 1;
    int beta = 1;
    double pathLength = 0;
    // Mersenne Twister random engine:
    int getRamdomValue(int minimum,int maximum){
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(minimum,maximum);
        return dist(rng);
    }

   private:
    void initToStart(int sizeOfGraph) {
        path.clear();
        passedCity.clear();
        passedCity.resize(sizeOfGraph, false);
        pathLength = 0;
        int random=getRamdomValue(0,sizeOfGraph-1);
        path.push_back(random);
        passedCity[random] = true;
    }

    std::map<int, double>* createDictionaryOfAvailablePaths(Graph* graph) {
        std::map<int, double>* result = new std::map<int, double>;
        for (int i = 0; i < graph->size(); ++i) {
            if ((std::fabs((*graph)(path.back(), i)) > std::numeric_limits<double>::epsilon()) &&
                (!passedCity[i]))
                result->insert(std::make_pair(i, (*graph)(path.back(), i)));
        }
        return result;
    }

    double calculateNumerator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap,
                              int currentIndex) {
        double eta = pow(1 / (*dictionaryOfAvailablePaths)[currentIndex], beta);
        double teta = pow(pheromonesMap(path.back(), currentIndex), alpha);
        return eta * teta;
    }

    double calcDenominator(std::map<int, double>* dictionaryOfAvailablePaths, const Matrix& pheromonesMap) {
        double sumOfAllProbabilities = 0.0;
        for (auto& i : (*dictionaryOfAvailablePaths)) {
            sumOfAllProbabilities +=
                pow(1 / i.second, beta) * pow(pheromonesMap(path.back(), i.first), alpha);
        }
        return sumOfAllProbabilities;
    }

    std::map<int, double>* calcProbabilities(Graph* graph, const Matrix& pheromonesMap) {
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

    void chooseWay(Graph* graph, std::map<int, double>* probabilities) {
        if (probabilities->size() == 1) {
            // std::cout<<path.back()<<' '<<(probabilities->begin()->first)<<'\n';
            double temp=(*graph)(path.back(),(probabilities->begin()->first));
            // std::cout<<"Added to path length:     "<< temp <<'\n';
            path.push_back(probabilities->begin()->first);
            // std::cout<<"Current  path length:   "<<pathLength<<'\n';
            pathLength = pathLength + temp;
            // std::cout<<"New  path length:   "<<pathLength<<'\n';
        } else {
            double randValue = getRamdomValue(1,100)/100.0;
            for (auto& it : (*probabilities)) {
                if (randValue <= it.second) {
                    // std::cout<<"randValue: "<<randValue<<"|it.second: "<<it.second<<'\n';
                    pathLength += (*graph)(path.back(), it.first);
                    passedCity[it.first] = true;
                    path.push_back(it.first);
                    break;
                }
            }
        }
    }

   public:
    Ant() =  default;
    void findPath(Graph* graph, const Matrix& pheromonesMap) {
        int sizeGraph = graph->size();
        initToStart(sizeGraph);
        for (int i = 1; i < sizeGraph; ++i) {
            std::map<int, double>* probabilities = calcProbabilities(graph, pheromonesMap);
            // std::cout<<"            Map size:"<<probabilities->size()<<std::endl;
            // std::cout<<"            Path size:"<<path.size()<<"\n";
            chooseWay(graph, probabilities);
            // std::cout<<"graph pathlength:  "<<pathLength<<'\n';
            // std::cout<<(*graph)(path[path.size()-2],path[path.size()-1])<<'\n';
            // for(auto& j:path)
            //     std::cout<<j<<" ";
            // std::cout<<"\n\n";
            delete probabilities;
        }
        pathLength += (*graph)(path.back(), path.front());
        path.push_back(path.front());
        // std::cout<<"graph pathlength:  "<<pathLength<<'\n';
        // std::cout<<(*graph)(path[path.size()-2],path[path.size()-1])<<'\n';
        // for(auto& i:path)
        //     std::cout<<i<<' ';
        // std::cout<<"\n\n";
    }
    void updatePheromones(Matrix* pheromonesMap) {
        double lengthInverse = 1 / pathLength;
        int sizeMap = pheromonesMap->size();
        for (int i = 0; i < sizeMap; ++i) {
            (*pheromonesMap)(path[0], path[0 + 1]) += (lengthInverse);
        }
    }
    double getPathLength() { return pathLength; }
    std::vector<int> getPath() { return path; }
};
}  // namespace s21