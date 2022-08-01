#pragma once 
template<typename T>
struct Node{
    Node* next=nullptr;
    T data;
    Node():data(){}
};