#pragma once
#include "node.h"
template<typename T>
class stack{
private:
    node<T>* data=nullptr;
    unsigned int size=0;
public:
    using value_type=T;
    stack(){}
    init():size(0),data(nullptr){
    }
};