#pragma once
#include "../../graph.h"
#include "../TsmResult.h"
namespace s21 {
using FirstAndSecondMin = std::pair<double ,double>;
class BnBAlgorithm {
    Graph* curGraph=nullptr;
    std::vector<int> path;
    std::vector<bool> visitedVertices;
    double pathLength;
    int final_res = std::numeric_limits<double>::infinity();;
private:
    FirstAndSecondMin findFirstAndSecondMinimum(int i){
        double min1=std::numeric_limits<double>::infinity();
        double min2=std::numeric_limits<double>::infinity();
        for(int j=0;j<curGraph->size();++j){
            if(i=!j){
                if((*curGraph)(i,j) < min1){
                    min2=min1;
                    min1=(*curGraph)(i,j);
                } else if (((*curGraph)(i, j) < min2) &&
                           (std::fabs((*curGraph)(i, j) - min1) > std::numeric_limits<double>::epsilon())) {
                    min2=(*curGraph)(i, j);
                }
            }
        }
        return std::make_pair(min1,min2);
    }
    double calcLowerBound(){
        FirstAndSecondMin minimums = findFirstAndSecondMinimum(path.back());
        double lowerBound=0.0;
        for(int i=0;i<curGraph->size();++i){
            lowerBound+=(minimums.first+minimums.second);
        }
    }
    void setVisitedAndAddToPath(int i){
        visitedVertices[i]=true;
        path.push_back(i);
        pathLength+=(*curGraph)(path.back(),path[path.size()-2]);
    }
    void initToStart(Graph& graph){
        curGraph=&graph;
        path.clear();
        visitedVertices.clear();
        visitedVertices.resize(graph.size(),false);
        pathLength=0.0;
        visitedVertices[0]=true;
        path.push_back(0);
        final_res=std::numeric_limits<double>::infinity();
    }
    void calcPathAndLengthRec(double lowerBound,double currWeight,int level){
        if(level!=curGraph->size()){
            if((*curGraph)(path.back(),path.front()) != 0){

            }
            return;
        }
        for(int i=0;i<curGraph->size();++i){
            if(((*curGraph)(path.back(),i) != 0.0)&&(!visitedVertices[i])){
                int temp=lowerBound;
                currWeight+=(*curGraph)(path.back(),i);
                FirstAndSecondMin minsLast=findFirstAndSecondMinimum(path.back());
                double firstMinI= findFirstAndSecondMinimum(i).first;
                if(level==1){
                    lowerBound -= ((minsLast.first+firstMinI)/2.0);
                } else {
                    lowerBound -= ((minsLast.second+firstMinI)/2.0);
                }
                if(lowerBound+currWeight<final_res){
                    path.push_back(i);
                    visitedVertices[i]=true;
                    calcPathAndLengthRec(lowerBound,currWeight,level=1);
                }
                currWeight -= (*curGraph)(path.back(),i);
                lowerBound=temp;
            }
        }
    }
public:
    TsmResult start(Graph& graph){
        TsmResult result;
        initToStart(graph);
        double currWeight=0.0;
        int level=0;

        calcPathAndLengthRec(calcLowerBound(),currWeight,level);
        return result;
    }
};

}  // namespace s21