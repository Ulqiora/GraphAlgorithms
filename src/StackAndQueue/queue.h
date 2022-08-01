#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>

#include "Node.h"
namespace s21 {
template <typename T>
class queue {
 private:
    Node<T>* topElem = nullptr;
    Node<T>* lastElem = nullptr;

 public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    void freeData();

 public:
    queue() {}
    explicit queue(queue&& other);
    explicit queue(const queue& other);
    explicit queue(const std::initializer_list<T> const& items);
    queue& operator=(const queue& other);
    queue& operator=(queue&& other);
    bool empty() const { return !topNode; }
    const_reference top() const {
        if (topElem) throw std::invalid_argument("This queue is empty!");
        return topElem->data;
    }
    void push(const_reference value);
    void pop();
    ~queue() { freeData(); }
    // void swap(queue& other);
    // size_type size() const;
    // void emplace_front() {}
    // template <class Type, class... Args>
    // void emplace_front(Type value, Args... args);
};
}  // namespace s21