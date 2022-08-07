#include "stack.h"

namespace s21 {

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
    Node<T>* node = topElem->next;
    delete topElem;
    topElem = node;
  }
}

}  // namespace s21