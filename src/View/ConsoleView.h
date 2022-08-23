#include <iostream>
#include <vector>
#include <string>

namespace s21 {
class ConsoleView {
    public:
        ConsoleView();
        ~ConsoleView();

    private:
        void printMenu();
        void waitForCommand();
        bool isNumber(std::string entry);
        void runCommand();
        void loadGraphMethod();
        void createImageMethod();
        void breadthTraversalMethod();
        void depthTraversalMethod();
        void shortestTwoMethod();
        void shortestAllMethod();
        void spanTreeMethod();
        void salesManMethod();

    private:
        unsigned int currentCommand = commandList::mainMenu;

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
            exit = 9
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
            "9. exit\n" \
        };
};
}  // namespace s21