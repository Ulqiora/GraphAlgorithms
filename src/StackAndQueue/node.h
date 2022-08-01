#pragma once 
template<typename T>
struct node{
    node* next=nullptr;
    T data;
    node():data(){}
};