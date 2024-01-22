#include <Graph/BnBAlgorithm/BnBAlgorithm.h>

namespace s21 {
    void BnBAlgorithm::createTree() {
        for (auto node: currentNodes) {
            node->createChildrens();
        }
        if (currentNodes[0]->sizeChildrens() < 2) return;
        if (currentNodes[1]->sizeChildrens() < 2) return;
        NodeBnB* minFirst = &((*currentNodes[0])(0));
        NodeBnB* minSecond = &((*currentNodes[1])(0));
        for (auto node: currentNodes) {
            for (int i = 0; i < node->sizeChildrens(); i++) {
                if (minFirst->getLowerBound() != (*node)(i).getLowerBound() &&
                    minSecond->getLowerBound() != (*node)(i).getLowerBound()) {
                    if (minFirst->getLowerBound() > (*node)(i).getLowerBound()) {
                        minSecond = minFirst;
                        minFirst = &(*node)(i);
                    } else if (minSecond->getLowerBound() > (*node)(i).getLowerBound()) {
                        minSecond = &(*node)(i);
                    }
                }
            }
        }
        currentNodes.clear();
        currentNodes.push_back(minFirst);
        currentNodes.push_back(minSecond);
        createTree();
    }

    void BnBAlgorithm::createTreeForRoot() {
        head.createChildrens();
        if (head.sizeChildrens() < 2) return;
        NodeBnB* minFirst = &head(0);
        NodeBnB* minSecond = &head(1);
        for (int i = 0; i < head.sizeChildrens(); i++) {
            if (minFirst->getLowerBound() != head(i).getLowerBound() &&
                minSecond->getLowerBound() != head(i).getLowerBound()) {
                if (minFirst->getLowerBound() > head(i).getLowerBound()) {
                    minSecond = minFirst;
                    minFirst = &head(i);
                } else if (minSecond->getLowerBound() > head(i).getLowerBound()) {
                    minSecond = &head(i);
                }
            }
        }
        currentNodes.clear();
        currentNodes.push_back(minFirst);
        currentNodes.push_back(minSecond);
    }
    TsmResult BnBAlgorithm::createTsmResult() {
        TsmResult result;
        NodeBnB* min = (currentNodes[0])->getLowerBound() < (currentNodes[1])->getLowerBound()
                               ? (currentNodes[0])
                               : (currentNodes[1]);
        result.vertices = min->path();
        result.vertices.push_back(result.vertices.front());
        for (auto& i: result.vertices) i++;
        result.distance = min->getLowerBound();
        return result;
    }
    void BnBAlgorithm::deepeningByOneLevel() {
        currentNodes[0] = &(currentNodes[0]->frontChildren());
        currentNodes[1] = &(currentNodes[1]->frontChildren());
    }

    TsmResult BnBAlgorithm::start(Graph& example, int startIndex) {
        head = NodeBnB(example, startIndex - 1);
        currentNodes.reserve(0);
        currentNodes.push_back(&head);
        graph = &example;
        createTreeForRoot();
        createTree();
        deepeningByOneLevel();
        return createTsmResult();
    }
}// namespace s21