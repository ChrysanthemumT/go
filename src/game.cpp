#include "game.hpp"
#include <memory>
#include <utility>

Game::Game() {
  board = std::make_shared<Board>();
  p1 = std::make_unique<Player>(0);
  p2 = std::make_unique<Player>(1);
}

void Game::makeMove(int x, int y) {
  int captured = board->placeStones(**turnPlayer, std::make_pair(x, y));
  (*turnPlayer)->capture(captured);
  changeTurn();
}

void Game::changeTurn() {
  if (*turnPlayer == p1.get())
    *turnPlayer = p2.get();
  else
    *turnPlayer = p1.get();
}
