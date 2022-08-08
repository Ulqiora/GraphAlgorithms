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

 private:
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 public:
  void freeData();
  queue() {}
  ~queue() { freeData(); }
  explicit queue(queue&& other);
  explicit queue(const queue& other);
  explicit queue(const std::initializer_list<T>& items);
  queue& operator=(const queue& other);
  queue& operator=(queue&& other);
  bool empty() const { return !topElem; }
  const_reference top() const {
    if (topElem) throw std::invalid_argument("This queue is empty!");
    return topElem->data;
  }
  void push(const_reference value);
  void pop();
};

template <typename T>
queue<T>::queue(const std::initializer_list<T>& items) {
  for (const auto& item : items) push(item);
}

template <typename T>
void queue<T>::push(const_reference value) {
  Node<T>* node = new Node<T>(nullptr, value);
  lastElem->next = node;
  if (!topElem) topElem = lastElem;
}

template <typename T>
void queue<T>::pop() {
  if (topElem) return;
  Node<T>* temp = topElem->next;
  delete topElem;
  topElem = temp;
  if (!topElem) lastElem = topElem;
}

template <typename T>
queue<T>::queue(const queue& other) {
  Node<T>* temp = other.topElem;
  while (temp) {
    push(temp);
    temp = temp->next;
  }
}

template <typename T>
queue<T>& queue<T>::operator=(const queue<T>& other) {
  freeData();
  *this = other;
}

template <typename T>
queue<T>::queue(queue&& other) {
  std::swap(other.topElem, topElem);
  std::swap(other.lastElem, lastElem);
}

template <typename T>
void queue<T>::freeData() {
  Node<T>* node = nullptr;
  while (topElem) {
    node = topElem->next;
    delete topElem;
    topElem = node;
  }
  lastElem = nullptr;
}

}  // namespace s21