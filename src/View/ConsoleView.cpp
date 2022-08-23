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
        if (isNumber(entry) && entry.length() == 1) {
            currentCommand = std::stoi(entry);
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
                breadthTraversalMethod();
                break;
            case depthTraversal:
                depthTraversalMethod();
                break;
            case shortestTwo:
                shortestTwoMethod();
                break;
            case shortestAll:
                shortestAllMethod();
                break;
            case spanTree:
                spanTreeMethod();
                break;
            case salesMan:
                salesManMethod();
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
        std::cout << "Creating image\n";
    }

    void ConsoleView::breadthTraversalMethod() {
        std::cout << "Breadth traverse\n";
    }

    void ConsoleView::depthTraversalMethod() {
        std::cout << "Depth traverse\n";
    }

    void ConsoleView::shortestTwoMethod() {
        std::cout << "Finding shortest two\n";
    }

    void ConsoleView::shortestAllMethod() {
        std::cout << "Finding shortest all\n";
    }

    void ConsoleView::spanTreeMethod() {
        std::cout << "Finding spaning tree\n";
    }

    void ConsoleView::salesManMethod() {
        std::cout << "Solving Salesman\n";
    }

    inline void ConsoleView::printMessage(const commandList& position) {
        std::cout << "***" << std::endl;
        std::cout << printable[position];
        std::cout << "***" << std::endl;
    }

}  // namespace s21

int main() {
    s21::ConsoleView con;
    return 0;
}