#pragma once
template <typename T>
struct Node {
  Node* next = nullptr;
  T data;
  Node() : data() {}
  Node(Node* other, const T& value) : next(other), data(value) {}
};