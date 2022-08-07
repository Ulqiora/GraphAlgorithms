#pragma once
#include <algorithm>
#include <initializer_list>

#include "Node.h"
namespace s21 {
template <typename T>
class stack {
 private:
  Node<T>* topElem = nullptr;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  void freeData();

 public:
  stack() {}
  explicit stack(stack&& other);
  explicit stack(const stack& other);
  explicit stack(const std::initializer_list<T>& items);
  stack& operator=(const stack& other);
  stack& operator=(stack&& other);
  bool empty() const { return !topElem; }
  const_reference top() const { return topElem->data; }
  void push(const_reference value);
  void pop();
  ~stack() { freeData(); }
  // void swap(stack& other);
  // size_type size() const;
  // void emplace_front() {}
  // template <class Type, class... Args>
  // void emplace_front(Type value, Args... args);
};
}  // namespace s21