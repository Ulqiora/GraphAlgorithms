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
template <typename T>
stack<T>::stack(stack&& other) {
  std::swap(topElem, other.topElem);
}

template <typename T>
stack<T>::stack(const stack& other) {
  *this = other;
}

template <typename T>
stack<T>::stack(const std::initializer_list<T>& items) {
  for (const auto& elem : items) push(elem);
}

template <typename T>
void stack<T>::push(const_reference value) {
  Node<T>* node = new Node<T>();
  node->next = topElem;
  node->data = value;
  topElem = node;
}

template <typename T>
void stack<T>::pop() {
  if (topElem == nullptr) return;
  Node<T>* last = topElem;
  topElem = topElem->next;
  delete last;
}

template <class T>
stack<T>& stack<T>::operator=(stack<T>&& other) {
  if (this == &other) return *this;
  if (topElem) freeData();
  std::swap(topElem, other.topNode);
  return *this;
}

template <class T>
stack<T>& stack<T>::operator=(const stack<T>& other) {
  if (topElem) {
    freeData();
  }
  Node<T>* copyTopNode = other.topElem;
  stack<T> reverse;
  while (copyTopNode != nullptr) {
    reverse.push(copyTopNode->data);
    copyTopNode = copyTopNode->next;
  }
  while (reverse.topNode != nullptr) {
    T data = reverse.pop_back();
    push(data);
  }
  return *this;
}

template <typename T>
void stack<T>::freeData() {
  Node<T>* node = nullptr;
  while (topElem) {
    node = topElem->next;
    delete topElem;
    topElem = node;
  }
}
}  // namespace s21