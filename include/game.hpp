#pragma once
#include "board.hpp"
#include "player.hpp"
#include <memory>

class Game {
public:
  Game();
  void makeMove(int x, int y);
  void changeTurn();

private:
  std::shared_ptr<Board> board;
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;
  Player **turnPlayer;
};
