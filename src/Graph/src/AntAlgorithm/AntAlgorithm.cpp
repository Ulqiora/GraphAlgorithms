#include <Graph/AntAlgorithm/AntAlgorithm.h>

namespace s21{
    void AntAlgorithm::initPheromonesMap() {
        pheromoneMap.setSize(graph->size());
        for (int i = 0; i < pheromoneMap.size(); ++i) {
            for (int j = 0; j < pheromoneMap.size(); ++j) {
                if (i != j) pheromoneMap(i, j) = startPheromone;
            }
        }
    }

    void AntAlgorithm::updatePheromoneMap() {
        pheromoneMap *= (1 - evaporationCoef);
        for (auto& ant : ants) {
            ant.updatePheromones(&pheromoneMap);
        }
    }

    void AntAlgorithm::updateTsmResult(TsmResult* result,int& numOfIteration) {
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

    void AntAlgorithm::createAnts() {
        ants.clear();
        ants.resize(graph->size(), Ant());
    }
    
    TsmResult AntAlgorithm::start(Graph* graphTest) {
        TsmResult result;
        if (!graphTest) throw std::invalid_argument("This graph is empty");
        graph = graphTest;
        initPheromonesMap();
        for (int numOfIteration=0; numOfIteration!=graph->size()*10; ) {
            createAnts();
            for (auto& i : ants) {
                i.findPath(graph, pheromoneMap);
            }
            updatePheromoneMap();
            updateTsmResult(&result,numOfIteration);
        }
        for(auto& i:result.vertices)
          i++;
        return result;
    }
}  // namespace s21