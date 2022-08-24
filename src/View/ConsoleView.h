#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../Model/graph.h"
#include "../Model/GraphAlgorithms.h"

namespace s21 {
class ConsoleView {
    private:
        Graph myGraph;
        GraphAlgorithms myAlgorithms;
        unsigned int currentCommand = mainMenu;

        enum commandList {
            mainMenu = 0,
            loadGraph = 1,
            createImage = 2,
            breadthTraversal = 3,
            depthTraversal = 4,
            shortestTwo = 5,
            shortestAll = 6,
            spanTree = 7,
            salesMan = 8,
            exit = 9,
            vertexNum = 10
        };

        std::vector<std::string> printable {
            "Choose one of the commands above\n" \
            "1. load the original graph from a file\n" \
            "2. create an image from the graph\n" \
            "3. graph traversal in breadth\n" \
            "4. graph traversal in depth\n" \
            "5. search for the shortest path between two vertices\n" \
            "6. search for the shortest paths between all pairs of vertices\n" \
            "7. search for the minimal spanning tree in the graph\n" \
            "8. solving the salesman problem\n" \
            "9. exit\n",  // 0
            "Enter the full path of the file\n",  // 1
            "Enter the name of the .dot file\n",  // 2
            "Breadth traversal result: \n",  // 3
            "Depth traversal result: \n",  // 4
            "Shortest path between two vertices: \n",  // 5
            "Shortest path between all vertices: \n",  // 6
            "Spanning tree result: \n",  // 7
            "Salesman problem result: \n",  // 8
            "Exit\n",  // 9
            "Enter the number of vertex: \n",  // 10
        };

    public:
        ConsoleView();
        ~ConsoleView();

    private:
        void runMenu();
        void waitForCommand();
        bool isNumber(std::string entry);
        void runCommand();
        void loadGraphMethod();
        void createImageMethod();
        void traversalMethod(const commandList& position);
        void shortestTwoMethod();
        void shortestAllMethod();
        void spanTreeMethod();
        void salesManMethod();
        inline void printMessage(const commandList& position);
};
}  // namespace s21