#include "ConsoleView.h"

namespace s21 {

    ConsoleView::ConsoleView() {
        runMenu();
        while (currentCommand != exit) {
            try {
                waitForCommand();
                runCommand();
            } catch (std::exception &e){
                std::cout << e.what() << std::endl;
                runMenu();
            }
        }
    }

    ConsoleView::~ConsoleView() {
    }

    void ConsoleView::runMenu() {
        currentCommand = mainMenu;
        runCommand();
    }

    void ConsoleView::waitForCommand() {
        std::string entry;
        std::cin >> entry;
        if (isNumber(entry) && (currentCommand = std::stoi(entry)) < 11) {
        } else {
            throw std::out_of_range("Wrong command!");
        }
    }

    bool ConsoleView::isNumber(std::string entry) {
        bool result = true;
        for (unsigned int i = 0; i < entry.size(); i++) {
            if (!std::isdigit(entry[i])) {
                result = false;
            }
        }
        return result;
    }

    void ConsoleView::runCommand() {
        switch (currentCommand) {
            case mainMenu:
                printMessage(mainMenu);
                break;
            case loadGraph:
                loadGraphMethod();
                break;
            case createImage:
                createImageMethod();
                break;
            case breadthTraversal:
                traversalMethod(breadthTraversal);
                break;
            case depthTraversal:
                traversalMethod(depthTraversal);
                break;
            case shortestTwo:
                shortestTwoMethod();
                break;
            case shortestAll:
                shortestOrSpanningMethod(shortestAll);
                break;
            case spanTree:
                shortestOrSpanningMethod(spanTree);
                break;
            case salesMan:
                salesManMethod();
                break;
            case bonus:
                salesManCompareMethod();
                break;
            case exit:
                break;
            default:
                runMenu();
                break;
        }
    }

    void ConsoleView::loadGraphMethod() {
        printMessage(loadGraph);
        std::string fileName;
        std::cin >> fileName;
        try {
            myGraph.loadGraphFromFile(fileName);
            std::cout << "Graph loaded succesfully. Graph size = " << myGraph.size() << std::endl;
        } catch (std::exception &e){
                std::cout << e.what() << std::endl;
        }
        currentCommand = mainMenu;
        runCommand();
    }

    void ConsoleView::createImageMethod() {
        if (myGraph.size() > 0) {
            printMessage(createImage);
            std::string fileName;
            std::cin >> fileName;
            try {
                myGraph.exportGraphToDot(fileName);
                std::cout << "File created successfully" << std::endl;
            } catch (std::exception &e){
                    std::cout << e.what() << std::endl;
            }
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    void ConsoleView::traversalMethod(const commandList& position) {
        if (myGraph.size() > 0) {
            printMessage(vertexNum);
            std::string vertexStr;
            std::cin >> vertexStr;
            std::vector<int> result;
            if (isNumber(vertexStr)) {
                int vertexInt = stoi(vertexStr);
                if (vertexInt < 1 || vertexInt > myGraph.size()) {
                    std::cout << "Wrong graph index!" << std::endl;
                } else {
                    if (position == breadthTraversal) {
                        result = myAlgorithms.breadthFirstSearch(myGraph, vertexInt);
                        printMessage(breadthTraversal);
                    } else {
                        result = myAlgorithms.depthFirstSearch(myGraph, vertexInt);
                        printMessage(depthTraversal);
                    }
                    for (unsigned int i = 0; i < result.size(); i++) {
                        std::cout << result[i] << ' ';
                    }
                    std::cout << std::endl;
                }
            }
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    void ConsoleView::shortestTwoMethod() {
        if (myGraph.size() > 0) {
            printMessage(vertexNum);
            std::string firstVertex, secondVertex;
            std::cin >> firstVertex;
            std::cin >> secondVertex;
            if (isNumber(firstVertex) && isNumber(secondVertex)) {
                try {
                    int firstNum = std::stoi(firstVertex);
                    int secondNum = std::stoi(secondVertex);
                    if (firstNum != secondNum && firstNum > 0 && secondNum > 0
                        && firstNum < myGraph.size() && secondNum < myGraph.size()) {
                        printMessage(shortestTwo);
                        std::cout << myAlgorithms.getShortestPathBetweenVertices(myGraph, firstNum, secondNum) << std::endl;
                    } else {
                        std::cout << "One or both values not correct!" << std::endl;
                    }
                } catch (std::exception &e){
                    std::cout << e.what() << std::endl;
                }
            } else {
                std::cout << "One or both values not correct!" << std::endl;
            }
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    void ConsoleView::shortestOrSpanningMethod(const commandList& position) {
        if (myGraph.size() > 0) {
            Matrix path;
            if (position == shortestAll) {
                path = myAlgorithms.getShortestPathsBetweenAllVertices(myGraph);
                printMessage(shortestAll);
            } else {
                path = myAlgorithms.getLeastSpanningTree(myGraph);
                printMessage(spanTree);
            }
            path.print();
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    void ConsoleView::salesManMethod() {
        if (myGraph.size() > 0) {
            TsmResult res;
            res = myAlgorithms.solveTravelingSalesmanProblem(myGraph);
            printMessage(salesMan);
            std::cout << "Distance = " << res.distance << std::endl;
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    void ConsoleView::salesManCompareMethod() {
        if (myGraph.size() > 0) {
            std::cout << "Enter the amount of cycles:" << std::endl;
            std::string strCycles;
            std::cin >> strCycles;
            if (isNumber(strCycles)) {
                int numCycles = std::stoi(strCycles);
                if (numCycles > 0) {
                    printMessage(bonus);
                    std::cout << "Ant time, ms = " << timeCompare(numCycles, antAlgo) << std::endl;
                    std::cout << "BnB time, ms = " << timeCompare(numCycles, bnbAlgo) << std::endl;
                    // std::cout << "BruteForce time, ms = " << timeCompare(numCycles, bruteAlgo) << std::endl;
                } else {
                    std::cout << "Wrong value!" << std::endl;
                }
            }
        } else {
            std::cout << "Incorrect graph!" << std::endl;
        }
        runMenu();
    }

    double ConsoleView::timeCompare(int numCycles, const commandList& algo) {
        std::chrono::time_point<std::chrono::system_clock> tStart = std::chrono::system_clock::now();
        if (algo == antAlgo) {
            for (int i = 0; i < numCycles; i++) {
                myAlgorithms.solveTravelingSalesmanProblem(myGraph);
            }
        } else if (algo == bnbAlgo) {
            for (int i = 0; i < numCycles; i++) {
                myAlgorithms.solveTravelingSalesmanProblemBnB(myGraph);
            }
        } else if (algo == bruteAlgo) {
            for (int i = 0; i < numCycles; i++) {
                myAlgorithms.solveTravelingSalesmanProblemBrudeForce(myGraph);
            }
        }
        std::chrono::time_point<std::chrono::system_clock> tFinish = std::chrono::system_clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(tFinish - tStart).count();
    }

    void ConsoleView::printMessage(const commandList& position) {
        std::cout << "***" << std::endl;
        std::cout << printable[position];
        std::cout << "***" << std::endl;
    }

}  // namespace s21
