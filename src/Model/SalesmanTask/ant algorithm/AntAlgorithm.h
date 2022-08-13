#pragma once
#include <algorithm>
#include <list>
#include <vector>

#include "../TsmResult.h"
#include "Ant.h"
#include "../../graph.h"
namespace s21 {

class AntAlgorithm {
    Graph* graph = nullptr;
    Matrix pheromoneMap;
    std::vector<Ant> ants;
    const int numOfIteration = 30;
    const int evaporationCoef = 0.5;
    void initPheromonesMap() {
        pheromoneMap.setSize(graph->size());
        for (int i = 0; i < pheromoneMap.size(); ++i) {
            for (int j = 0; j < pheromoneMap.size(); ++j) {
                if (i != j) pheromoneMap(i, j) = startPheromone;
            }
        }
    }

    void updatePheromoneMap() {
        pheromoneMap *= (1 - evaporationCoef);
        for (auto& ant : ants) {
            ant.updatePheromones(&pheromoneMap);
        }
    }

    void updateTsmResult(TsmResult* result,int& numOfIteration) {
        std::list<double> paths;
        for (auto& ant : ants) paths.push_back(ant.getPathLength());
        double minimumPath = *(std::min_element(paths.begin(), paths.end()));
        if (minimumPath < result->distance) {
            for (auto& ant : ants) {
                // std::cout<<"New step: pathSize="<<ant.getPathLength()<<'\n';
                if (std::fabs(ant.getPathLength() - minimumPath)<std::numeric_limits<double>::epsilon() ) {
                    result->vertices = ant.getPath();
                    result->distance = minimumPath;
                    // std::cout<<"set path for tsm"<<'\n';
                    numOfIteration=0;
                    break;
                }
            }
        } else {
          numOfIteration++;
        }
    }

    void createAnts() {
        ants.clear();
        ants.resize(graph->size(), Ant());
    }
    
   public:
    AntAlgorithm() = default;
    TsmResult start(Graph* graphTest) {
        TsmResult result;
        if (!graphTest) throw std::invalid_argument("This graph is empty");
        graph = graphTest;
        initPheromonesMap();
        for (int numOfIteration=0; numOfIteration!=graph->size()*10; ) {
            createAnts();
            // std::cout<<"NumOfAnts"<<ants.size()<<'\n';
            // std::cout<<" numOfIteration:"<<numOfIteration<<'\n';
            for (auto& i : ants) {
                // std::cout<<"    numOfAnt:"<<0<<'\n';
                i.findPath(graph, pheromoneMap);
            }
            updatePheromoneMap();
            updateTsmResult(&result,numOfIteration);
            std::cout<<"Current best path length = "<<result.distance<<'\n';
            std::cout <<"Current best path = ";
            for(auto& j:result.vertices)
              std::cout<<j<<' ';
            std::cout<<'\n';
        }
        return result;
    }

   private:
    const double startPheromone = 0.33;
};

}  // namespace s21