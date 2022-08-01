#pragma once
#include <initializer_list>
#include <algorithm>
#include "Node.h"
namespace s21{
template<typename T>
class stack{
private:
    Node<T>* topElem=nullptr;
    unsigned int size=0;
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
public:
    stack(){}
    explicit stack(stack&& other);
    explicit stack(const stack& other);
    explicit stack(const std::initializer_list<T> const& items);
    ~stack() { emptyStack(); }
    void push(const_reference value);
    void pop();
    const_reference top() const { return topElem->data; }
    void swap(stack& other);
    size_type size() const;
    bool empty() const { return !topNode; }
    stack& operator=(stack&& other);
    stack& operator=(const stack& other);
    void emplace_front() {}
    template <class Type, class... Args>
    void emplace_front(Type value, Args... args);
};
}