#pragma once
#include <map>
#include <vector>
#include <memory>
#include <random>
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
    int numOfEpochs = 30;
    double pathLength = 0;
    // fixed seed
    const int seed = 123;
    // Mersenne Twister random engine:
    std::mt19937 urbg {seed};  
    std::uniform_int_distribution<int> dist {0, 100};

   private:
    void updatePheromones() {}
    void initToStart(int sizeOfGraph) {
        passedСity.resize(sizeOfGraph,false);
        pathLength=0;
        path.push_back(0);
        passedСity[0]=true;
    }
    double calculateProbability(double lenght, double pheromoneOfEdge){

    }

    std::shared_ptr<std::map<int,double>> calcProbabilities(Graph* graph, const Matsrix& pheromonesMap){
        std::map<int,double>* probabilities=new std::map<int,double>;
        double probability=0.0;
        for(int i=1;i<graph->size();++i){
            if((*graph)(path.back(),i)!=0 && !(passedСity[i])){
                probability += calculateProbability((*graph)(path.back(), i), pheromonesMap(path.back() - 1, i - 1));
                probabilities->insert(std::make_pair(i, probability));
            }
        }
        return std::make_shared<std::map<int,double>>(probabilities);
    }

    void chooseWay(Graph* graph,std::shared_ptr<std::map<int,double>> probabilities){
        if (probabilities->size() == 1) {
            path.push_back(probabilities->begin()->first);
        } else {
            double randValue=dist(urbg);
            for (auto& it:(*probabilities)) {
                if (randValue <= it.second) {
                    pathLength+=(*graph)(path.back(),it.first);
                    passedСity[it.first]=true;
                    path.push_back(it.first);
                    break;
                }
            }
            pathLength+=(*graph)(path.front(),path.back());
            path.push_back(path.front());
        }
    }

   public:
    Ant() = default;
    void findPath(Graph* graph, const Matrix& pheromonesMap) {
        initToStart(graph->size());
        for(int i=1;i<graph->size();++i){
            std::shared_ptr<std::map<int,double>> probabilities =calcProbabilities(graph,pheromonesMap);
            chooseWay(graph,probabilities);
        }
    }
};
}  // namespace s21