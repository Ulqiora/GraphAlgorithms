#pragma once 
#include <vector>
struct TsmResult {
    std::vector<int> vertices;
    double distance=std::numeric_limits<double>::infinity();
};