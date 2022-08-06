#pragma once
#include
#include "../../graph.h"
namespace s21 {

class Ant {
 private:
  std::vector<int> bannedСity;
  std::vector<int> passedCities;
  const int proximityRatio = 1;
  const int alpha = 1;
  const int beta = 1;
  const int evaporationCoef = 0.2;

 public:
  Ant() = default;
  void findWay(Graph* graph, Matrix pheromonesMap) {}
  void clearBannedCity() { bannedСity.clear(); }
};
}  // namespace s21