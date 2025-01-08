#pragma once
#include "player.hpp"
#include <bitset>
#include <vector>

class Board {
public:
  Board(size_t size) : b(size, std::vector<int>(0)) {};
  int placeStones(Player &player, std::pair<int, int> coord);

private:
  std::vector<std::vector<int>> b;
  std::bitset<25> bi;
  const int captureStones();
};
