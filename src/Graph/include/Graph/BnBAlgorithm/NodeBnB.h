#pragma once 
#include <vector>
#include <list>
#include <iomanip>
#include "MatrixBnB.h"
namespace s21 {

class NodeBnB {
private:
    MatrixBnB matrix;
    double NodeBnBCost=0;
    double lowerBound = 0;
    std::vector<NodeBnB> childrens;
    std::vector<int> currentPath;
public:
    NodeBnB(const MatrixBnB& matrixNew,int startIndex): matrix(matrixNew),currentPath(0){
        currentPath.push_back(startIndex);
        double sumMinOfRows=matrix.reducedRowsAndCalcMinimums();
        double sumMinOfCols=matrix.reducedColsAndCalcMinimums();
        NodeBnBCost=sumMinOfCols+sumMinOfRows;
    }
    NodeBnB(const NodeBnB& NodeBnBOther, int indexFVert, int indexSVert): childrens(0) {
        if(indexFVert != NodeBnBOther.currentPath.back())
            throw std::invalid_argument("Error of start vertex  in edge");
        matrix=NodeBnBOther.matrix.createCopyWithoutEdge(indexFVert, indexSVert);
        currentPath=NodeBnBOther.currentPath;
        currentPath.push_back(indexSVert);
        lowerBound = (NodeBnBOther.matrix(indexFVert, indexSVert) == numLimD::infinity()
                          ? 0
                          : NodeBnBOther.matrix(indexFVert, indexSVert));
        lowerBound+=matrix.reducedColsAndCalcMinimums()+matrix.reducedRowsAndCalcMinimums();
        lowerBound+=(NodeBnBOther.NodeBnBCost==numLimD::infinity()?0:NodeBnBOther.NodeBnBCost);
        NodeBnBCost=lowerBound;
    }
    NodeBnB(const NodeBnB& other) =default;
    NodeBnB()=default;
    NodeBnB(const Graph& graph,int startIndex):matrix(graph){
        currentPath.push_back(startIndex);
        double sumMinOfRows=matrix.reducedRowsAndCalcMinimums();
        double sumMinOfCols=matrix.reducedColsAndCalcMinimums();
        NodeBnBCost=sumMinOfCols+sumMinOfRows;
    }
    void print()const noexcept{
        std::cout<<"lower bound="<<lowerBound<<'\n';
        for(auto& row:matrix){
            for(auto& cell: row){
                std::cout<<" w = "<<std::setw(5)<<cell<<" | ";
            }
            std::cout<<'\n';
        }
    }
    void createChildrens(){
        for(size_t i=0;i<matrix.size();++i){
            if(std::find(currentPath.begin(),currentPath.end(),i)==currentPath.end()){
                childrens.push_back((NodeBnB((*this),currentPath.back(),i)));
            }
        }
    }
    int sizeChildrens() const {return childrens.size();}
    auto begin()const{return childrens.begin();}
    auto end()const{return childrens.end();}
    double getLowerBound() const {return lowerBound;}
    void setLowerBound(double value) { lowerBound=value; }
    NodeBnB& frontChildren(){ return childrens.front();}
    std::vector<int> path() { return currentPath;}
    NodeBnB& operator()(int i) {return childrens[i];}
};
}  // namespace s21