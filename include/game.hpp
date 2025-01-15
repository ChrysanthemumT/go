#pragma once
#include "board.hpp"
#include "player.hpp"
#include "result.hpp"
#include <memory>

class Game {
public:
  Game();
  void makeMove(int x, int y);
  void changeTurn();
  bool pass();
  void resetPass();
  void reset();
  std::unique_ptr<Result> endGame();

private:
  std::shared_ptr<Board> board;
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;
  std::pair<bool, bool> passState;
  Player *turnPlayer;
};
