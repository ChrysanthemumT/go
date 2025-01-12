#pragma once
#include "player.hpp"
#include <bitset>
#include <vector>

class Board {
public:
  Board(size_t size) : board(size, std::vector<int>(size, 0)) {};
  int placeStones(Player &player, std::pair<int, int> coord);

private:
  std::vector<std::vector<int>> board;
  std::bitset<25> bi;
  int captureStones(Player &player);
  std::pair<bool, int> floodfill(std::vector<std::vector<int>> &, int,
                                 std::pair<int, int>);
  void draw();
};
