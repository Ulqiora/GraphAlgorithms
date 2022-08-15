#pragma once
#include <iostream>
namespace s21 {
struct Index {
    int row, col;
    Index() = default;
    Index(const Index& other) = default;
    Index(int row, int col) : row(row), col(col) {}
    Index(Index&& other) {
        std::swap(row, other.row);
        std::swap(col, other.col);
    }
    ~Index() = default;
};
}  // namespace s21